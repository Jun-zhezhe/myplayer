#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QTimer>
#include <QVector>

#include <vector>
using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    static int speed;
    static int this_time;
    static int length_time;

private slots:
    void on_play_clicked();

    void on_mute_clicked();

    void on_voladd_clicked();

    void on_volsub_clicked();

    void on_close_clicked();

    void on_Progress_sliderReleased();

    void on_Progress_sliderPressed();

    void on_Songslist_itemClicked(QListWidgetItem *item);

    void on_mode_clicked();

    void on_last_clicked();

    void on_next_clicked();

    void on_Refresh_clicked();

    void on_background_clicked();

private:
    Ui::Widget *ui;

    QTimer *time;
    int vol;
    void Mydir();

};

#endif // WIDGET_H
