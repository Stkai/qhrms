#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private:
    Ui::LoginForm *ui;
private slots:
    void on_buttonBox_accepted();
};

#endif // LOGINFORM_H
