#### 常规操作
```
git init //初始化版本库
----------------------------------------------------------------------------   
//github的使用
ssh-keygen -t rsa -C “807564945@qq.com” //github的ssh创建

git remote add origin git@github.com:Nzzz/learngit.git  //关联远程库

git clone git@github.com:Nzzz/learngit.git //把远程库克隆到本地库

------------------------------------------------------------------------------------
//更新内容时（工作区->暂存区->版本库）：
//直接修改文件即修改工作区			
git add <filename>  //把工作区文件添加到暂存区

git commit -m <"说明"> //把暂存区文件添加到master版本库

git push -u origin master //把本地库的内容推送到远程，即把当前分支master推送到远程
                             第一次推送master分支时，加上了-u参数
-----------------------------------------------------------------------------							 
//查看仓库的情况：
git status//时刻掌握仓库当前的状态

git diff//虽然Git告诉我们readme.txt被修改了，但如果能看看具体修改了什么内容，自然是很好的。
         比如你休假两周从国外回来，第一天上班时，已经记不清上次怎么修改的readme.txt，
         所以，需要用git diff这个命令
		 
git log (--pretty=oneline)//差看有几个版本被提交到Git仓库里

git reflog   //查看命令历史，以便确定要回到未来的哪个版本
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
```

#### 内容回退
```
//更新内容出错需要回退时：
git checkout -- <fliename>//用版本库里的版本替换工作区的版本，
                           无论工作区是修改还是删除，都可以“一键还原”
git reset --hard HEAD^ //有几个^表示前几个版本，HEAD为当前版本，或 HEAD~88为前88个版本，
                       回到哪个版本，HEAD指针指向哪个版本  （--hard会修改工作区的内容 ，--soft 则不会更改工作区，只撤销提交：git reset --soft HEAD^）或者git reset --hard <版本号>

git reset HEAD <filename>//可以把暂存区的修改撤销掉（unstage），重新放回工作区

若远程分支已经被错误提交则本地回退后直接git push -f 

git rm <filename>  //删除版本库的文件

-----------------------------------------------------------------------------

// 丢弃本地的更改（不merge），方便重新git pull
git stash
git stash drop 

---------------------------------------------------
// 当错误提交了大文件到远程仓库，所有仓库都要本地更新
git rev-list --all | xargs -rL1 git ls-tree -r --long | sort -uk3 | sort -rnk4 | head -10 查看排名前十的大文件
git filter-branch --tree-filter "rm -f {filepath}" -- --all  在所有记录中强行删除大文件
git push -f --all  强行提交到远程仓库，所有相关的本地仓库必须按以上方法删除才能与远程不冲突
```

#### 分支管理
```
查看分支：git branch

创建分支：git branch <name>

切换分支：git checkout <name>

创建+切换分支：git checkout -b <name>

合并某分支到当前分支：git merge <name>

删除分支：git branch -d <name>

删除远程分支： git push origin :<name>

将远程分支和本地分支合并: git pull origin (远程分支名):(本地分支名)
```
