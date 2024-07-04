# 使用python+Flask 框架实现的论坛

## 主要功能：

    用户注册和登录
    查看所有帖子和帖子详情
    发布新帖子
    删除已发布的帖子（需要登录，仅作者或管理员可以删除）

写了一个bat文件，内容是这样的：
@echo off

REM 打开第一个命令窗口并执行命令
start cmd /k "cd C:\Users\MF_Training_PC\Desktop\new & timeout /t 1 & python app.py"

REM 等待一段时间，然后打开第二个命令窗口并执行命令
timeout /t 3
start cmd /k "curl https://i996.me/tmhe67191|cmd"

REM 使用默认浏览器打开指定网址
timeout /t 7
start  https://smilefan.i996.me

REM 批处理脚本结束
exit

用这个应该可以直接一键内网穿透了，具体是关注微信公众号的敲代码斯基，里面有详细的获取，直接用我上面的也行
不过要设置好cd的目录，这样一键运行好，域名不会轻易改了

