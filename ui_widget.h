/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_3;
    QPushButton *mode;
    QPushButton *last;
    QPushButton *volsub;
    QSlider *Progress;
    QPushButton *close;
    QListWidget *Songslist;
    QPushButton *next;
    QPushButton *play;
    QLabel *vol;
    QLabel *label_2;
    QPushButton *voladd;
    QPushButton *mute;
    QPushButton *background;
    QPushButton *Refresh;
    QLabel *name;
    QLabel *song;
    QLabel *singer;
    QLabel *album;
    QLabel *make;
    QLabel *lrc;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/113.jpg")));
        label->setScaledContents(true);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(526, 400, 67, 17));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignCenter);
        mode = new QPushButton(Widget);
        mode->setObjectName(QStringLiteral("mode"));
        mode->setGeometry(QRect(80, 490, 60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/16.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode->setIcon(icon);
        mode->setIconSize(QSize(50, 50));
        mode->setFlat(true);
        last = new QPushButton(Widget);
        last->setObjectName(QStringLiteral("last"));
        last->setGeometry(QRect(180, 490, 60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        last->setIcon(icon1);
        last->setIconSize(QSize(50, 50));
        last->setFlat(true);
        volsub = new QPushButton(Widget);
        volsub->setObjectName(QStringLiteral("volsub"));
        volsub->setGeometry(QRect(930, 500, 60, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        volsub->setIcon(icon2);
        volsub->setIconSize(QSize(50, 50));
        volsub->setFlat(true);
        Progress = new QSlider(Widget);
        Progress->setObjectName(QStringLiteral("Progress"));
        Progress->setGeometry(QRect(35, 420, 521, 31));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        Progress->setPalette(palette);
        Progress->setCursor(QCursor(Qt::PointingHandCursor));
        Progress->setMouseTracking(true);
        Progress->setMaximum(99);
        Progress->setOrientation(Qt::Horizontal);
        close = new QPushButton(Widget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(950, 20, 60, 60));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/11.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon3);
        close->setIconSize(QSize(50, 50));
        close->setFlat(true);
        Songslist = new QListWidget(Widget);
        Songslist->setObjectName(QStringLiteral("Songslist"));
        Songslist->setGeometry(QRect(620, 50, 256, 341));
        QPalette palette1;
        QBrush brush2(QColor(191, 64, 64, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush6(QColor(145, 145, 145, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        Songslist->setPalette(palette1);
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        Songslist->setFont(font);
        Songslist->setMouseTracking(false);
        Songslist->setTabletTracking(false);
        Songslist->setFocusPolicy(Qt::NoFocus);
        Songslist->setStyleSheet(QLatin1String("background-color: rgba(191, 64, 64, 0);\n"
"\n"
""));
        Songslist->setAutoScroll(true);
        Songslist->setProperty("isWrapping", QVariant(false));
        Songslist->setUniformItemSizes(false);
        Songslist->setSortingEnabled(false);
        next = new QPushButton(Widget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(380, 490, 60, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon4);
        next->setIconSize(QSize(50, 50));
        next->setFlat(true);
        play = new QPushButton(Widget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(280, 490, 60, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon5);
        play->setIconSize(QSize(50, 50));
        play->setFlat(true);
        vol = new QLabel(Widget);
        vol->setObjectName(QStringLiteral("vol"));
        vol->setGeometry(QRect(930, 410, 67, 17));
        vol->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(14, 400, 67, 17));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setKerning(true);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        voladd = new QPushButton(Widget);
        voladd->setObjectName(QStringLiteral("voladd"));
        voladd->setGeometry(QRect(930, 430, 60, 60));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/7.png"), QSize(), QIcon::Normal, QIcon::Off);
        voladd->setIcon(icon6);
        voladd->setIconSize(QSize(50, 50));
        voladd->setFlat(true);
        mute = new QPushButton(Widget);
        mute->setObjectName(QStringLiteral("mute"));
        mute->setGeometry(QRect(480, 490, 60, 60));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        mute->setIcon(icon7);
        mute->setIconSize(QSize(50, 50));
        mute->setFlat(true);
        background = new QPushButton(Widget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(850, 500, 60, 60));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/20.png"), QSize(), QIcon::Normal, QIcon::Off);
        background->setIcon(icon8);
        background->setIconSize(QSize(50, 50));
        background->setFlat(true);
        Refresh = new QPushButton(Widget);
        Refresh->setObjectName(QStringLiteral("Refresh"));
        Refresh->setGeometry(QRect(850, 430, 60, 60));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/19.png"), QSize(), QIcon::Normal, QIcon::Off);
        Refresh->setIcon(icon9);
        Refresh->setIconSize(QSize(50, 50));
        Refresh->setFlat(true);
        name = new QLabel(Widget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(120, 80, 350, 43));
        QFont font2;
        font2.setPointSize(15);
        name->setFont(font2);
        name->setFocusPolicy(Qt::NoFocus);
        name->setFrameShape(QFrame::NoFrame);
        name->setAlignment(Qt::AlignCenter);
        song = new QLabel(Widget);
        song->setObjectName(QStringLiteral("song"));
        song->setGeometry(QRect(120, 139, 350, 43));
        song->setFont(font2);
        song->setFocusPolicy(Qt::NoFocus);
        song->setFrameShape(QFrame::NoFrame);
        song->setAlignment(Qt::AlignCenter);
        singer = new QLabel(Widget);
        singer->setObjectName(QStringLiteral("singer"));
        singer->setGeometry(QRect(120, 183, 350, 43));
        singer->setFont(font2);
        singer->setFocusPolicy(Qt::NoFocus);
        singer->setFrameShape(QFrame::NoFrame);
        singer->setAlignment(Qt::AlignCenter);
        album = new QLabel(Widget);
        album->setObjectName(QStringLiteral("album"));
        album->setGeometry(QRect(120, 227, 350, 43));
        album->setFont(font2);
        album->setFocusPolicy(Qt::NoFocus);
        album->setFrameShape(QFrame::NoFrame);
        album->setAlignment(Qt::AlignCenter);
        make = new QLabel(Widget);
        make->setObjectName(QStringLiteral("make"));
        make->setGeometry(QRect(120, 271, 350, 43));
        make->setFont(font2);
        make->setFocusPolicy(Qt::NoFocus);
        make->setFrameShape(QFrame::NoFrame);
        make->setAlignment(Qt::AlignCenter);
        lrc = new QLabel(Widget);
        lrc->setObjectName(QStringLiteral("lrc"));
        lrc->setGeometry(QRect(70, 320, 450, 45));
        QPalette palette2;
        QBrush brush7(QColor(115, 210, 22, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        QBrush brush8(QColor(190, 190, 190, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        lrc->setPalette(palette2);
        QFont font3;
        font3.setPointSize(17);
        lrc->setFont(font3);
        lrc->setFocusPolicy(Qt::NoFocus);
        lrc->setLayoutDirection(Qt::LeftToRight);
        lrc->setFrameShape(QFrame::NoFrame);
        lrc->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        label_3->setText(QApplication::translate("Widget", "00:00", nullptr));
        mode->setText(QString());
        last->setText(QString());
        volsub->setText(QString());
        close->setText(QString());
        next->setText(QString());
        play->setText(QString());
        vol->setText(QString());
        label_2->setText(QApplication::translate("Widget", "00:00", nullptr));
        voladd->setText(QString());
        mute->setText(QString());
        background->setText(QString());
        Refresh->setText(QString());
        name->setText(QString());
        song->setText(QString());
        singer->setText(QString());
        album->setText(QString());
        make->setText(QString());
        lrc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
