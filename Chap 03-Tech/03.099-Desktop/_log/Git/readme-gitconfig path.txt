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

Git�������������config�ļ����ֱ���system��global��local���ڵ�ǰ�����У��ֱ��Ӧ%GitPath%\mingw64\etc\gitconfig�ļ���$home.gitconfig�ļ���%RepoPath%.git\config�ļ�������%GitPath%ΪGit�İ�װ·����%RepoPath%Ϊĳ�ֿ�ı���·��������system��������ϵͳֻ��һ����global����ÿ���˻�ֻ��һ������local���ú�git�ֿ����Ŀ��ͬ������ֻ���ڲֿ�Ŀ¼���ܿ��������á�


�鿴ϵͳconfig

git config --system --list

�鿴��ǰ�û���global������

git config --global  --list

�鿴��ǰ�ֿ�������Ϣ

git config --local  --list


�ɴ˿ɼ��Cglobal�д洢���ύ�û���email���û��� �����Ҫ�ֶ����������ʹ������ָ��

git config --global user.name "myname"
git config --global user.email  "test@gmail.com"

�����������������ȡ��config������ֲ�ҳ����:

git help config

