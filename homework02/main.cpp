#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct
{
    QString num;
    QString name;
    QVector<int> scores;
} studData;

QDebug operator<< (QDebug d, const studData &data)
{
    int i;
        for(i=0;i<data.student.size();i++)
            d<<data.student.at(i);
     return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn)
    {
    case SK::col01:
        d1.num<d2.num;
        break;
    case SK::col02:
        d1.name<d2.name;
        break;
    case SK::col03:
    case SK::col04:
    case SK::col05:
    case SK::col06:
    case SK::col07:
    case SK::col08:
    case SK::col09:
    case SK::col10:
    case SK::col11:
    case SK::col12:
    case SK::col13:
    case SK::col14:
    case SK::col15:
    case SK::col16:
    case SK::col17:
    case SK::col18:
    case SK::col19:
    case SK::col20:
    case SK::col21:
    case SK::col22:
    case SK::col23:
    case SK::col24:
    case SK::col25:
    case SK::col26:
    case SK::col27:
    case SK::col28:
    case SK::col29:
    case SK::col30:
    case SK::col31:
    case SK::col32:
        d1.scores<d2.scores;
        break;
    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    // ...
    // 请补全该类，使其实现上述要求
    // ...
}

// 请补全
ScoreSorter::ScoreSorter(QString dataFile){
}


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 自定义qDebug
}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
