/********************************************************************************
** Form generated from reading UI file 'graphs.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHS_H
#define UI_GRAPHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graphs
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphs_view;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_vert_btn;
    QPushButton *del_vert_btn;
    QPushButton *add_rib_btn;
    QPushButton *del_rib_btn;
    QPushButton *bfs_btn;
    QPushButton *dfs_btn;
    QPushButton *travel_btn;
    QPushButton *question_btn;
    QLineEdit *info_line;
    QLabel *label;
    QLabel *info_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Graphs)
    {
        if (Graphs->objectName().isEmpty())
            Graphs->setObjectName(QString::fromUtf8("Graphs"));
        Graphs->resize(1223, 699);
        centralwidget = new QWidget(Graphs);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphs_view = new QGraphicsView(centralwidget);
        graphs_view->setObjectName(QString::fromUtf8("graphs_view"));
        graphs_view->setGeometry(QRect(10, 10, 871, 631));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(890, 10, 321, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_vert_btn = new QPushButton(verticalLayoutWidget);
        add_vert_btn->setObjectName(QString::fromUtf8("add_vert_btn"));

        verticalLayout->addWidget(add_vert_btn);

        del_vert_btn = new QPushButton(verticalLayoutWidget);
        del_vert_btn->setObjectName(QString::fromUtf8("del_vert_btn"));

        verticalLayout->addWidget(del_vert_btn);

        add_rib_btn = new QPushButton(verticalLayoutWidget);
        add_rib_btn->setObjectName(QString::fromUtf8("add_rib_btn"));

        verticalLayout->addWidget(add_rib_btn);

        del_rib_btn = new QPushButton(verticalLayoutWidget);
        del_rib_btn->setObjectName(QString::fromUtf8("del_rib_btn"));

        verticalLayout->addWidget(del_rib_btn);

        bfs_btn = new QPushButton(verticalLayoutWidget);
        bfs_btn->setObjectName(QString::fromUtf8("bfs_btn"));

        verticalLayout->addWidget(bfs_btn);

        dfs_btn = new QPushButton(verticalLayoutWidget);
        dfs_btn->setObjectName(QString::fromUtf8("dfs_btn"));

        verticalLayout->addWidget(dfs_btn);

        travel_btn = new QPushButton(verticalLayoutWidget);
        travel_btn->setObjectName(QString::fromUtf8("travel_btn"));

        verticalLayout->addWidget(travel_btn);

        question_btn = new QPushButton(verticalLayoutWidget);
        question_btn->setObjectName(QString::fromUtf8("question_btn"));

        verticalLayout->addWidget(question_btn);

        info_line = new QLineEdit(centralwidget);
        info_line->setObjectName(QString::fromUtf8("info_line"));
        info_line->setGeometry(QRect(890, 470, 311, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(890, 440, 291, 16));
        info_label = new QLabel(centralwidget);
        info_label->setObjectName(QString::fromUtf8("info_label"));
        info_label->setGeometry(QRect(890, 500, 331, 131));
        Graphs->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Graphs);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1223, 25));
        Graphs->setMenuBar(menubar);
        statusbar = new QStatusBar(Graphs);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Graphs->setStatusBar(statusbar);

        retranslateUi(Graphs);

        QMetaObject::connectSlotsByName(Graphs);
    } // setupUi

    void retranslateUi(QMainWindow *Graphs)
    {
        Graphs->setWindowTitle(QApplication::translate("Graphs", "Graphs", nullptr));
        add_vert_btn->setText(QApplication::translate("Graphs", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        del_vert_btn->setText(QApplication::translate("Graphs", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        add_rib_btn->setText(QApplication::translate("Graphs", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        del_rib_btn->setText(QApplication::translate("Graphs", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        bfs_btn->setText(QApplication::translate("Graphs", "\320\236\320\261\321\205\320\276\320\264  \320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        dfs_btn->setText(QApplication::translate("Graphs", "\320\236\320\261\321\205\320\276\320\264  \320\262 \320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));
        travel_btn->setText(QApplication::translate("Graphs", "\320\234\320\265\321\202\320\276\320\264 \320\262\320\265\321\202\320\262\320\265\320\271 \320\270 \320\263\321\200\320\260\320\275\320\270\321\206", nullptr));
        question_btn->setText(QApplication::translate("Graphs", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label->setText(QApplication::translate("Graphs", "\320\237\320\276\320\273\320\265 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270:", nullptr));
        info_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Graphs: public Ui_Graphs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHS_H
