#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<QString> number,name,t1,t2;
    number<<"1403130209"<<"1403140101"<<"1403140102"<<"1403140103"; //输入数据
    name<<"鲁智深"<<"林冲"<<"宋江"<<"武松";
    t1<<"80"<<"82"<<"76"<<"88";
    t2<<"72"<<"76"<<"85"<<"80";
    QVector<QVector<QString>> transcript;
    transcript<<number<<name<<t1<<t2;
    qDebug("成绩单如下:");//输出数据
    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";
        for(int i=0;i<4;i++)
            qDebug()<<number.at(i).toInt()<<"\t"
                    <<name.at(i)<<"\t"
                    <<t1.at(i).toInt()<<"\t"
                    <<t2.at(i).toInt();
    qDebug()<<"按姓名排序：";
    std::sort(name.begin(),name.end(),std::greater<QString>());
    int i,j;
    for(i=0;i<name.size();i++)
    {
        for(j=0;j<name.size();j++)
            if(name.at(i)==transcript.at(1).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"按课程1的成绩排序：";
    std::sort(t1.begin(),t1.end(),std::greater<QString>());
    for(i=0;i<t1.size();i++)
    {
        for(j=0;j<t1.size();j++)
            if(t1.at(i)==transcript.at(2).at(j))
        break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"按课程2的成绩排序：";
    std::sort(t2.begin(),t2.end(),std::greater<QString>());
    for(i=0;i<t2.size();i++)
    {
        for(j=0;j<t2.size();j++)
            if(t2.at(i)==transcript.at(3).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    return a.exec();
}
