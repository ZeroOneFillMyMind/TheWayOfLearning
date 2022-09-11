# git

## 1 操作记录

```
subsys@DESKTOP-6MHAMD7:/mnt/f/Code/boost$ ssh-keygen -t rsa -C "yzj1995@126.com"
Generating public/private rsa key pair.
Enter file in which to save the key (/home/subsys/.ssh/id_rsa):
Created directory '/home/subsys/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /home/subsys/.ssh/id_rsa
Your public key has been saved in /home/subsys/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:l/n+I+8sPzmzt3x7QOHLfqfjZFmI4Z2RzbSjYZaQhfk yzj1995@126.com
The key's randomart image is:
+---[RSA 3072]----+
|           .=.  .|
|           +. o=.|
|            o*o+o|
|           +oE=+.|
|        S + o++..|
|         . .  +o |
|            ..+o |
|           .o+X *|
|            .OX#*|
+----[SHA256]-----+
subsys@DESKTOP-6MHAMD7:/mnt/f/Code/boost$ cat ~/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCza1Rdp06YWkge9ObzIBNZd88h8mYZj5+zUoLng9bXonyrtl3kRXUBIFEumtxNmAram9v0qSZCpDwITK6e+tkepFXXDvP63z821zdXdNpt4+ThRMB1iZqL9eSS48MsdJ7BkNs2Rw2ejrOGJ/170pcKgAGieA6jdgUZ6dfkOa8gFmkbztH4C9yInD4O2lSkHtERJ8002D0+s1uPaIS8xa0XHXpGXij264rV87Ju3JjIRpqQrkxVWB9zW+aqNCLBBdsqpi6H62nZB7v7sr3Zq+pBcbOXkj6ISF1Sq81U0bOiDCeQnPzWnRtbwE/3S5zqtB5ojcIj3cohvZ6Yp6WdrCRGvxxJ+sMdlI2UdQtLbiyAP9058FsQm7O/Hdbt99XpWWfpcdbOEPyTjNAL1apdcdXY4RPWuoxi203u9N3cLZlJ8X5pMHkNTmiI2ir3tSo3rL5SU57kTJDWWhp05DvKNJL2bAfURfhGug+I5BcAixdXS1XT3LhYM2y2tu5NX+B7Jdc= yzj1995@126.com
subsys@DESKTOP-6MHAMD7:/mnt/f/Code/boost$ ssh -T git@github.com
The authenticity of host 'github.com (20.205.243.166)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])?
Host key verification failed.
subsys@DESKTOP-6MHAMD7:/mnt/f/Code/boost$ ssh -T git@github.com
The authenticity of host 'github.com (20.205.243.166)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.
Hi ZeroOneFillMyMind! You've successfully authenticated, but GitHub does not provide shell access.
```