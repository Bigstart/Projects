from flask import Blueprint, request, render_template, redirect, url_for
from flask_login import login_required, login_user, logout_user, current_user
from werkzeug.security import check_password_hash, generate_password_hash


from models import User, Post, db


routes = Blueprint("routes", __name__)

@routes.route('/')
def index():
    posts = Post.query.order_by(Post.timestamp.desc()).all()
    return render_template('index.html', posts=posts)

@routes.route('/login', methods=['GET', 'POST'])
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

@routes.route('/register', methods=['GET', 'POST'])
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

@routes.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect('/')

@routes.route('/user_profile')
@login_required
def user_profile():
    user_posts = Post.query.filter_by(user_id=current_user.id).order_by(Post.timestamp.desc()).all()
    return render_template('user_profile.html', user=current_user, posts=user_posts)


@routes.route('/new_post', methods=['GET', 'POST'])
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

@routes.route('/delete_post/<int:post_id>', methods=['POST'])
@login_required
def delete_post(post_id):
    post = Post.query.get(post_id)
    if post and (post.user == current_user or current_user.is_admin):
        db.session.delete(post)
        db.session.commit()
        return redirect(url_for("routes.index")) # 修改了这一行

