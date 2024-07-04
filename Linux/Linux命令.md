# Linux命令基础格式
无论是什么命令，用于什么用途，在Linux中，命令有其通用的格式：
command [-options] [parameter]
·command:命令本身
·-option:[可选，非必填]命令的一些选项，可以通过选项控制命令的行为细节
·parameter：[可选，非必填]命令的参数，多数用于命令的指向目标
语法中的[]表示可选的意思

示例：
·  ls -l /home/itheima, ls是命令本身，-l是选项，/home/itheima是参数
  · 意思是以列表的形式，显示/home/itheima目录中的内容
·  cp -r test1 test2,cp是命令本身，-r是选项，test1和test2是参数
  · 意思是复制文件夹test1成为test2

  # ls命令入门
  ls命令的作用是列出目录下的内容，语法细节如下：
  ls [-a -l -h] [Linux路径]
  · -a -l -h 是可选的选项
  · Linux路径是此命令可选的参数
  当不使用选项和参数，直接使用ls命令本体，表示：以平铺形式，列出当前工作目录下的内容
  ## HOME目录：每个Linux操作用户在Linux系统的个人账户目录，路径在：/home/用户名