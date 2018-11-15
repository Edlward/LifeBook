C:\Users\jerhua\.gitconfig
C:\Users\jerhua\.ssh\...

https://blog.csdn.net/u014296452/article/details/79984867

#gitlab
cd ~/workspace/gitlab
git init
git config --global user.name 'gitlab'
git config --global user.email 'gitlab@company.com'

#github
cd ~/workspace/github
git init
git config --local user.name 'personal'
git config --local user.email 'personal@163.com'

Git共有三个级别的config文件，分别是system、global和local。在当前环境中，分别对应%GitPath%\mingw64\etc\gitconfig文件、$home.gitconfig文件和%RepoPath%.git\config文件。其中%GitPath%为Git的安装路径，%RepoPath%为某仓库的本地路径。所以system配置整个系统只有一个，global配置每个账户只有一个，而local配置和git仓库的数目相同，并且只有在仓库目录才能看到该配置。


查看系统config

git config --system --list

查看当前用户（global）配置

git config --global  --list

查看当前仓库配置信息

git config --local  --list


由此可见–global中存储了提交用户的email和用户名 如果需要手动设置则可以使用如下指令

git config --global user.name "myname"
git config --global user.email  "test@gmail.com"

可以运行如下命令获取对config命令的手册页帮助:

git help config

