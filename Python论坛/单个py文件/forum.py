#导入必要的库和模块
from flask import Flask, request, render_template, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
from flask_login import LoginManager, UserMixin, login_required, login_user, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash

#创建Flask应用实例
app = Flask(__name__)
#配置数据库,使用SQLite数据库
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///forum.db'
#设置秘钥,用于session加密
app.config['SECRET_KEY'] = 'my_secret_key'
#为应用创建SQLAlchemy实例
db = SQLAlchemy(app)


#定义用户模型
class User(UserMixin, db.Model):
    #设定数据表
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(100), nullable=False, unique=True)
    password = db.Column(db.String(255), nullable=False)
    is_admin = db.Column(db.Boolean, default=False)


#定义帖子模型
class Post(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(100), nullable=False)
    content = db.Column(db.Text, nullable=False)
    timestamp = db.Column(db.DateTime, default=datetime.utcnow)
    user_id = db.Column(db.Integer, db.ForeignKey("user.id"))
    user = db.relationship("User", backref="posts")

# 实例化一个 LoginManager 对象
login_manager = LoginManager()
# 设置登录视图函数名称，这将用作登录要求的重定向页面
login_manager.login_view = "login"
# 初始化登陆管理对象
login_manager.init_app(app)


# 用户加载函数，用于获取用户
@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

# 首页路由，展示所有帖子
@app.route('/')
def index():
    posts = Post.query.order_by(Post.timestamp.desc()).all()
    return render_template('index.html', posts=posts)


# 登录路由
@app.route('/login', methods=['GET', 'POST'])
def login():
    if current_user.is_authenticated:
        return redirect('/')
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        if user and check_password_hash(user.password, password):
            login_user(user)
            return redirect('/')
        else:
            return render_template('login.html', error="用户名或密码错误")
    return render_template('login.html')


# 注册路由
@app.route('/register', methods=['GET', 'POST'])
def register():
    if current_user.is_authenticated:
        return redirect('/')
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        existing_user = User.query.filter_by(username=username).first()
        if existing_user:
            return render_template('register.html', error="用户名已存在")
        else:
            user = User(username=username, password=generate_password_hash(password))
            db.session.add(user)
            db.session.commit()
            login_user(user)
            return redirect('/')
    return render_template('register.html')


# 登出路由
@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect('/')


# 新建帖子路由
@app.route('/new_post', methods=['GET', 'POST'])
@login_required
def new_post():
    if request.method == 'POST':
        post_title = request.form['title']
        post_content = request.form['content']
        new_post = Post(title=post_title, content=post_content, user=current_user)
        db.session.add(new_post)
        db.session.commit()
        return redirect('/')
    return render_template('new_post.html')


# 删除帖子路由
@app.route('/delete_post/<int:post_id>', methods=['POST'])
@login_required
def delete_post(post_id):
    post = Post.query.get(post_id)
    if post and (post.user == current_user or current_user.is_admin):
        db.session.delete(post)
        db.session.commit()
        return redirect('/')
    else:
        return render_template('index.html', posts=Post.query.all(), error="您没有权限执行此操作")


# 在应用上下文中创建表格
with app.app_context():
    db.create_all()

# 启动应用
if __name__ == "__main__":
    app.run(debug=True)
