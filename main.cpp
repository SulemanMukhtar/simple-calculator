#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <cmath>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget();
    window->setWindowTitle("Calculator");
    QLineEdit *display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(50);
    QPushButton *buttons[20];
    QString buttonLabels[20] = {"7", "8", "9", "+",
                                "4", "5", "6", "-",
                                "1", "2", "3", "*",
                                "0", ".", "C", "/",
                                "sin", "cos", "log", "sqrt"};
    for (int i = 0; i < 20; ++i)
    {
        buttons[i] = new QPushButton(buttonLabels[i]);
    }
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(display, 0, 0, 1, 5);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            layout->addWidget(buttons[i*4+j], i+1, j);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        layout->addWidget(buttons[16+i], i+1, 4);
    }
    QObject::connect(buttons[0], SIGNAL(clicked()), display, SLOT(insert("7")));
    QObject::connect(buttons[1], SIGNAL(clicked()), display, SLOT(insert("8")));
    QObject::connect(buttons[2], SIGNAL(clicked()), display, SLOT(insert("9")));
    QObject::connect(buttons[3], SIGNAL(clicked()), display, SLOT(insert("+")));
    QObject::connect(buttons[4], SIGNAL(clicked()), display, SLOT(insert("4")));
    QObject::connect(buttons[5], SIGNAL(clicked()), display, SLOT(insert("5")));
    QObject::connect(buttons[6], SIGNAL(clicked()), display, SLOT(insert("6")));
    QObject::connect(buttons[7], SIGNAL(clicked()), display, SLOT(insert("-")));
    QObject::connect(buttons[8], SIGNAL(clicked()), display, SLOT(insert("1")));
    QObject::connect(buttons[9], SIGNAL(clicked()), display, SLOT(insert("2")));
    QObject::connect(buttons[10], SIGNAL(clicked()), display, SLOT(insert("3")));
    QObject::connect(buttons[11], SIGNAL(clicked()), display, SLOT(insert("*")));
    QObject::connect(buttons[12], SIGNAL(clicked()), display, SLOT(insert("0")));
    QObject::connect(buttons[13], SIGNAL(clicked()), display, SLOT(insert(".")));
    QObject::connect(buttons[14], SIGNAL(clicked()), display, SLOT(clear()));
    QObject::connect(buttons[15], SIGNAL(clicked()), display, SLOT(insert("/")));
    QObject::connect(buttons[16], SIGNAL(clicked()), display, SLOT(insert("sin(")));
    QObject::connect(buttons[17], SIGNAL(clicked()), display, SLOT(insert("cos(")));
    QObject::connect(buttons[18], SIGNAL(clicked()), display, SLOT(insert("log(")));
    QObject::connect(buttons[19], SIGNAL(clicked()), display, SLOT(insert("sqrt(")));
    QObject::connect(buttons[16], SIGNAL(clicked()), [&display](){ display->setText(QString::number(std::sin(display->text().toDouble()))); });
    QObject::connect(buttons[17], SIGNAL(clicked()), [&display](){ display->setText(QString::number(std::cos(display->text().toDouble()))); });
    QObject::connect(buttons[18], SIGNAL(clicked()), [&display](){ display->setText(QString::number(std::log10(display->text().toDouble()))); });
    QObject::connect(buttons[19], SIGNAL(clicked()), [&display](){ display->setText(QString::number(std::sqrt(display->text().toDouble()))); });
    window->setLayout(layout);
    window->show();
    return app.exec();
}
