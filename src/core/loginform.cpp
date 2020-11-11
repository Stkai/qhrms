#include "loginform.h"
#include "ui_loginform.h"
#include <QDialogButtonBox>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    setWindowTitle("管理员登陆");
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

LoginForm::~LoginForm()
{
    delete ui;
}


void LoginForm::on_buttonBox_accepted()
{
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    //    if(ui->lineEdit_username->text() == tr("root") &&
    //            ui->lineEdit_password->text() == tr("1"))
    //    {
    qDebug()<<"ok";
    QStringList drivers = QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    db.setDatabaseName("qhrms.db");
    db.setUserName(ui->lineEdit_username->text());
    db.setPassword(ui->lineEdit_password->text());
    //打开数据库
    if(!db.open())
    {
        qDebug()<<ui->lineEdit_username->text();
        qDebug()<<ui->lineEdit_password->text();
        //标题              内容                OK按钮

    }else {
        QSqlQuery query;
        query.exec(QString("select username,password from admin where %1 = username and %1 = password")
                   .arg(ui->lineEdit_username->text())
                   .arg(ui->lineEdit_password->text()));
        if(query.next())
        {
            qDebug()<<"登录成功";
            qDebug() << query.value(0).toString() << query.value(1).toString() ;
            accept();
        }else {
            QMessageBox::warning(this, tr("登录失败！"),tr("用户名或密码错误！"),QMessageBox::Yes);
            // 清空输入框内容
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            //光标定位
            ui->lineEdit_username->setFocus();
            qDebug()<<"error";
        }
    }
}
