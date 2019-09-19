#include "widget.h"
#include "ui_widget.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <QString>
#include <QDebug>
#include <string.h>
#include "fun.h"
extern struct MyTyep{
    int fifo_fd;
    int fd[2];
}Mytype;
//bool only_song = false;
bool Single = false;
vector<char *> song_list;
bool state = true;
bool start = true;
bool state_bar = true;
bool mute = true;
int song_numb = 0;
int song_new = 0;
int pattern = 2;
int background = 0;
int lrc_num = 0;

int Widget::speed = 0;
int Widget::this_time = 0;
int Widget::length_time = 0;
LRC *lrc_hand = NULL;
void *deal_fun1(void *);
void *deal_fun2(void *);
void player_mode(Ui::Widget *ui);
void Highlight(Ui::Widget *ui);
void lrc_handle(Ui::Widget *ui);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/140.jpg"));
    setWindowTitle(QString("哲哲的播放器"));
    hide();
    setWindowFlags(Qt::WindowStaysOnTopHint);
    show();

    hide();
    setWindowFlags(Qt::Widget);
    show();
    vol = 80;

    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1,NULL,deal_fun1,(void *)ui);
    pthread_create(&tid2,NULL,deal_fun2,NULL);
    pthread_detach(tid1);
    pthread_detach(tid2);

    char buf[64] = "";
    sprintf(buf,"%s %d 1","volume",vol);

    //printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    Widget::Mydir();
}
void *deal_fun1(void *arg)
{
    Ui::Widget * ui = (Ui::Widget *)arg;
    while(1)
    {
        //Highlight(ui);
        char buf[128] = "";
        read(Mytype.fd[0],buf,sizeof(buf));
        //qDebug()<<buf<<endl;
        //printf("buf = %s\n",buf);
        char cmd[128] = "";
        float num = 0.0f;
        sscanf(buf,"%[^=]=%f",cmd,&num);

        if(strcmp(cmd,"ANS_PERCENT_POSITION") == 0)
        {
            Widget::speed =  (int)(num+0.5);
            //printf("\r已播放%05.2f%%\t",num);
            if(state_bar)
                ui->Progress->setValue(Widget::speed);
        }
        else if(strcmp(cmd,"ANS_TIME_POSITION") == 0)
        {
            Widget::this_time = (int)(num*10+0.5);
            char buf[64] = "";
            sprintf(buf,"%02d:%02d.%d",Widget::this_time/10/60,Widget::this_time/10%60,Widget::this_time%10);
            ui->label_2->setText(QString(buf));
            if(Widget::this_time >= Widget::length_time*10-10 && Widget::this_time > 10)
            {
                //Highlight(ui);
                state = false;
                ui->play->setIcon(QIcon(":/img/1.png"));
                usleep(150000);
                player_mode(ui);
            }
            if(lrc_hand != NULL)
            {
                lrc_num = 4;
                while(myprint(lrc_hand,lrc_num)->next != NULL)
                {
                    int lrc_time1 = myprint(lrc_hand,lrc_num)->time_min*600+myprint(lrc_hand,lrc_num)->time_sec*10+myprint(lrc_hand,lrc_num)->time_ms/10;
                    int lrc_time2 = myprint(lrc_hand,lrc_num+1)->time_min*600+myprint(lrc_hand,lrc_num+1)->time_sec*10+myprint(lrc_hand,lrc_num+1)->time_ms/10;
                    if(Widget::this_time >= lrc_time1 && Widget::this_time <= lrc_time2)
                    {
                        //printf("%s\n",myprint(lrc_hand,lrc_num)->buf);
                        ui->lrc->setText(QString(myprint(lrc_hand,lrc_num)->buf));
                    }
                    lrc_num++;
                }
            }
        }
        else if(strcmp(cmd,"ANS_LENGTH") == 0)
        {
            Widget::length_time = (int)(num+0.5);
            //printf("播放总时间 %d", Widget::length_time);
            char buf[64] = "";
            sprintf(buf,"%02d:%02d",Widget::length_time/60,Widget::length_time%60);
            ui->label_3->setText(QString(buf));
        }
        fflush(stdout);
        //Highlight(ui);
    }
}
void *deal_fun2(void *)
{
    while(1)
    {
        while(state)
        {
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_percent_pos\n",strlen("get_percent_pos\n"));//获得百分比
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_time_pos\n",strlen("get_time_pos\n"));//获得时间
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_time_length\n",strlen("get_time_length\n"));
        }
        usleep(1000);
    }
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_play_clicked()//播放暂停
{
    if(state)
    {
        state = false;
        usleep(50000);
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        ui->play->setIcon(QIcon(":/img/1.png"));
    }
    else
    {
        state = true;
        usleep(50000);
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        ui->play->setIcon(QIcon(":/img/4.png"));
    }
}

void Widget::on_mute_clicked()//静音
{
    char buf[64] = "";
    sprintf(buf,"%s\n","mute");
    write(Mytype.fifo_fd,buf,strlen(buf));
    if(mute)
    {
        mute = false;
        ui->mute->setIcon(QIcon(":/img/6.png"));
    }
    else
    {
        mute = true;
        ui->mute->setIcon(QIcon(":/img/9.png"));
    }
}

void Widget::on_voladd_clicked()//音量加
{
    if(vol >= 100)
        return;
    else
        vol += 5;
    if(state)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        //printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
    ui->vol->setText(QString("音量:")+QString::number(vol));
    QTimer::singleShot(1000,NULL,[=](){
        ui->vol->setText("");
    });
}

void Widget::on_volsub_clicked()//音量减
{
    if(vol <= 0)
        return;
    else
        vol -= 5;
    if(state)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        //printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
    ui->vol->setText(QString("音量:")+QString::number(vol));
    QTimer::singleShot(1000,NULL,[=](){
        ui->vol->setText("");
    });
}

void Widget::on_close_clicked()//关闭
{
    write(Mytype.fifo_fd,"quit\n",strlen("quit\n"));
    usleep(1000*10);
    song_list.clear();
    usleep(1000*10);
    //write(Mytype.fifo_fd,"quit\n",strlen("quit\n"));
    this->close();
}


void Widget::on_Progress_sliderReleased()//进度条释放
{
    if(ui->Progress->value() != Widget::speed)
    {
        usleep(5000*10);
        int i = ((ui->Progress->value()-Widget::speed)*(Widget::length_time)/100);
        if(i == 0)
            return;
        char buf[128] = "";
        sprintf(buf,"%s %d\n","seek",i);
        //printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        if(!state)
            write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        state_bar = true;
    }
}

void Widget::on_Progress_sliderPressed()//进度条按下
{
    state_bar = false;
}

void Widget::Mydir()//读取目录
{
    int counter =ui->Songslist->count();
    for(int index=0;index<counter;index++)
    {
        QListWidgetItem *item = ui->Songslist->takeItem(0);
        delete item;
    }

    DIR *dir = opendir("./song/");
    while(1)
    {
        struct dirent *ent =readdir(dir);
        if(ent == NULL)
            break;
        else if(ent->d_type == DT_REG)
        {
            char buf[128] = "";
            //qDebug()<<ent->d_name<<endl;
            sscanf(ent->d_name,"%*[^.].%s",buf);
            //printf("%s\n",buf);
            if(strcmp("mp3",buf) == 0)
            {
                ui->Songslist->addItem(QString(ent->d_name));
                char *str = new char[strlen(ent->d_name)+1];
                strcpy(str,ent->d_name);
                song_list.push_back(str);
                //printf("----%s\n",ent->d_name);
            }
        }
    }
    song_numb = song_list.size();
}

void Highlight(Ui::Widget * ui)
{
    for(int i = 0;i < song_numb;i++)
    {
        ui->Songslist->item(i)->setFlags(Qt::ItemIsEditable);
        if(strcmp(song_list[song_new],ui->Songslist->item(i)->text().toUtf8().data()) == 0)
        {
            ui->Songslist->item(song_new)->setTextColor(QColor(Qt::red));
        }
        else
        {
            ui->Songslist->item(i)->setTextColor(QColor(Qt::black));
        }
    }
    lrc_handle(ui);
}

void Widget::on_Songslist_itemClicked(QListWidgetItem *item)//点击歌词列表条目
{

    //printf("%s\n",item->text().toUtf8().data());
    char buf[256] = "";
    sprintf(buf,"%s ./song/%s\n","loadfile",item->text().toUtf8().data());
    //printf("%s\n",buf);
    for(int i = 0;i < song_numb;i++)
    {
        if(strcmp(song_list[i],item->text().toUtf8().data()) == 0)
        {
            song_new = i;
            ui->Songslist->item(i)->setTextColor(QColor(Qt::red));
        }
    }
    //ui->Songslist->setStyleSheet("QListView::item:selected:active{background:rgb(0,0,223);}\QListView::item:selected:!active{background:rgb(0,0,223);}");
    Highlight(ui);
    write(Mytype.fifo_fd,buf,strlen(buf));
    ui->play->setIcon(QIcon(":/img/4.png"));
    state = true;

    usleep(1000);

}
void player_mode(Ui::Widget * ui)
{
    if(pattern == 1)//单曲循环
    {

    }
    else if(pattern == 2)//列表循环
    {
        if(start)
        {
            start = false;
        }
        else
        {
            if(song_new >= song_numb-1)
                song_new = 0;
            else
                song_new++;
        }
    }
    else if(pattern == 3)//随机播放
    {
        srand(time(NULL));
        song_new = rand()%song_numb;
    }
    else
        return;
    state = true;
    ui->play->setIcon(QIcon(":/img/4.png"));
    char buf[128] = "";
    sprintf(buf,"%s \"./song/%s\"\n","loadfile",song_list[song_new]);
    Highlight(ui);
    write(Mytype.fifo_fd,buf,strlen(buf));
    Highlight(ui);
    usleep(1000);

}
void Widget::on_mode_clicked()
{
    if(pattern == 2)
    {
        pattern = 1;//单曲循环
        Single = true;
        ui->mode->setIcon(QIcon(":/img/12.png"));
    }
    else if(pattern == 1)
    {
        pattern = 2;//列表循环
        Single = false;
        ui->mode->setIcon(QIcon(":/img/16.png"));
    }

    else if(pattern == 3)
    {
        pattern = 3;//随机播放
        Single = false;
        ui->mode->setIcon(QIcon(":/img/17.png"));
    }
}

void Widget::on_last_clicked()//上一首
{
    if(!Single)
    {
        if(song_new <= 0)
            song_new = song_numb-1;
        else
            song_new--;
    }
    ui->play->setIcon(QIcon(":/img/4.png"));
    state = true;
    char buf[256] = "";
    sprintf(buf,"%s \"./song/%s\"\n","loadfile",song_list[song_new]);
    write(Mytype.fifo_fd,buf,strlen(buf));
    usleep(1000);
    Highlight(ui);
}


void Widget::on_next_clicked()//下一首
{
    if(!Single)
    {
        if(song_new >= song_numb-1)
            song_new = 0;
        else
            song_new++;
    }
    ui->play->setIcon(QIcon(":/img/4.png"));
    state = true;
    char buf[256] = "";
    sprintf(buf,"%s \"./song/%s\"\n","loadfile",song_list[song_new]);
    write(Mytype.fifo_fd,buf,strlen(buf));
    usleep(1000);
    Highlight(ui);
}

void Widget::on_Refresh_clicked()
{
    //printf("刷新歌单\n");
    for(int i = 0;i < song_numb;i++)
        delete song_list[i];
    song_list.clear();
    Widget::Mydir();
    Highlight(ui);
}

void Widget::on_background_clicked()//
{
    static int num = 131;
    char buf[64] = "";
    //num++;
    sprintf(buf,":/img/%d.jpg",num >= 131 ? (num = 121):++num);
    //printf("%s\n",buf);
    QPixmap pix;
    pix.load(buf);
    pix = pix.scaled(1024,600);
    ui->label->setPixmap(pix);
}
void lrc_handle(Ui::Widget *ui)
{
    if(lrc_hand != NULL)
    {
        free_link(&lrc_hand);
    }
    lrc_num = 0;
    ui->lrc->setText(QString("暂无歌词"));
    ui->name->setText(QString("正在播放：")+QString(song_list[song_new]));
    char buf[128] = "";
    char str[128] = "";
    sscanf(song_list[song_new],"%[^.]",buf);
    strcat(buf,".lrc");
    sprintf(str,"./song/%s",buf);
    //printf("%s\n",str);
    int i = filelrc(&lrc_hand,str);
    //printf("----%d---\n",i);
    if(lrc_hand != NULL)
    {
        ui->song->setText(QString("歌名：")+QString(QString(myprint(lrc_hand,0)->buf)));
        ui->singer->setText(QString("歌手：")+QString(QString(myprint(lrc_hand,1)->buf)));
        ui->album->setText(QString("专题：")+QString(QString(myprint(lrc_hand,2)->buf)));
        ui->make->setText(QString("制作：")+QString(QString(myprint(lrc_hand,3)->buf)));
    }
    else
    {
        ui->song->setText(QString("歌名：")+QString(QString(song_list[song_new])));
        ui->singer->setText(QString("歌手：")+QString("未知"));
        ui->album->setText(QString("专题：")+QString("未知"));
        ui->make->setText(QString("制作：")+QString("未知"));
    }
}
