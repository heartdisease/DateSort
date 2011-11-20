/********************************************************************************
** Form generated from reading UI file 'DateSortWidget.ui'
**
** Created: Sat Aug 20 01:23:54 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESORTWIDGET_H
#define UI_DATESORTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateSortWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *dirField;
    QPushButton *browseButton;
    QPushButton *sortButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *console;

    void setupUi(QWidget *DateSortWidget)
    {
        if (DateSortWidget->objectName().isEmpty())
            DateSortWidget->setObjectName(QString::fromUtf8("DateSortWidget"));
        DateSortWidget->resize(597, 341);
        gridLayout = new QGridLayout(DateSortWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DateSortWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dirField = new QLineEdit(DateSortWidget);
        dirField->setObjectName(QString::fromUtf8("dirField"));

        gridLayout->addWidget(dirField, 0, 1, 1, 1);

        browseButton = new QPushButton(DateSortWidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(browseButton->sizePolicy().hasHeightForWidth());
        browseButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/folder-search.png"), QSize(), QIcon::Normal, QIcon::Off);
        browseButton->setIcon(icon);

        gridLayout->addWidget(browseButton, 0, 2, 1, 1);

        sortButton = new QPushButton(DateSortWidget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setMinimumSize(QSize(0, 43));

        gridLayout->addWidget(sortButton, 1, 0, 1, 3);

        groupBox = new QGroupBox(DateSortWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        console = new QTextEdit(groupBox);
        console->setObjectName(QString::fromUtf8("console"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy1);
        console->setReadOnly(true);

        horizontalLayout->addWidget(console);


        gridLayout->addWidget(groupBox, 2, 0, 1, 3);


        retranslateUi(DateSortWidget);

        QMetaObject::connectSlotsByName(DateSortWidget);
    } // setupUi

    void retranslateUi(QWidget *DateSortWidget)
    {
        DateSortWidget->setWindowTitle(QApplication::translate("DateSortWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DateSortWidget", "Verzeichnis:", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QString());
        sortButton->setText(QApplication::translate("DateSortWidget", "Sortieren", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DateSortWidget", " Konsole ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DateSortWidget: public Ui_DateSortWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATESORTWIDGET_H
