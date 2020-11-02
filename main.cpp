#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LoginForm loginForm;
    if(loginForm.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}
