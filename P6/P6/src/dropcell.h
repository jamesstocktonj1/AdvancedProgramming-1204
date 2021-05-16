#ifndef DROPCELL_H
#define DROPCELL_H

#include <QWidget>
#include <QSpinBox>


class DropCell : public QWidget {
    Q_OBJECT

public: 
    DropCell(QWidget *parent = nullptr);

private:
    QSpinBox *spinbox;
};







#endif