﻿# EducationManager
一个教务管理系统
这个软件用Visual Studio2012作为工具，MFC框架开发的，目的：方便多媒体管理人员的管理工作，

<h1>程序运行需要VC++和MFC dll</h1>


数据库文件在DataBase文件夹中，
用这个数据库文件创建一个数据源名为“ Building ”，
这样，该软件就能从数据源内读取数据了，



使用说明：
添加：
当你要添加一个新数据，首先清空数据，然后在输入框里输入新的信息，点击插入按钮，
删除：
首先选中你想删除的行，然后点击删除按钮
编辑，首先选中你想编辑的行，然后修改数据，然后点击保存修改，



CClassRoomManagerApp类：控制整个软件
CClassRoomManagerSet类：控制对数据库的访问    由CRecordSet派生而来
CClassRoomManagerDoc类：控制软件的文档
CAboutDlg类：控制关于窗口
MainFrm类：控制菜单区域
Room类：控制教室信息对话框
Input类：控制输入对话框
ExChange类：用以数据交换的类，里面是5个静态变量




