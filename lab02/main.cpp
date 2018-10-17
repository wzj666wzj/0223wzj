#include <QCoreApplication>
#include<QDebug>
#include<QList>

typedef quint32 word;
typedef quint8 byte;

#define str(s) #s//字符串转译

#define word_hhi(x) ((byte)((word)((word)(x)>>24)))//最高八位
#define word_lhi(x) ((byte)((word)((word)(x)>>16)&255))//次高八位
#define word_hlo(x) ((byte)(((word)(x)>>8)&255))//次低八位
#define word_llo(x) ((byte)((word)(x)&255))//最低八位

#define max(x,y) (((x)>(y))?(x):(y))//求最大值
#define min(x,y) (((x)<(y))?(x):(y))//求最小值
int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    int i=0x12345678;
    QList<qint8> values;//将结果存入此地址
    values.append(word_hhi(i));//添加新对象
    values.append(word_lhi(i));//添加新对象
    values.append(word_hlo(i));//添加新对象
    values.append(word_llo(i));//添加新对象
    int j;
    j=(values.at(2)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+values.at(1);//重组数的值
    qDebug("原始值:0x%x==%d\n最低八位:0x%x==%d\n次低八位:0x%x==%d\n次高八位:0x%x==%d\n最高八位:0x%x==%d\n",
    i,i,values.at(3),values.at(3),values.at(2),values.at(2),values.at(1),values.at(1),values.at(0),values.at(0));
    qDebug("最高八位和次高八位的最大值:0x%x(%d)\n次低八位和最低八位的最小值:0x%x(%d)",
    max(values.at(0),values.at(1)),max(values.at(1),values.at(0)),min(values.at(2),values.at(3)),min(values.at(3),values.at(2)));
    qDebug("重新组合后的数值:0x%x(%d)",j,j);
    qDebug()<<"排序前:"<<values;
    std::sort(values.begin(),values.end(),std::greater<qint8>());//从大到小进行排序
    qDebug()<<"排序后:"<<values;
    return 0;
}
