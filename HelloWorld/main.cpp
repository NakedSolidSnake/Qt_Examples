#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    a.setApplicationName("Hello World");
    a.setApplicationVersion("0.1");

    int num = 1;

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption numOption("n", "The number argument", "number", "1");
    QCommandLineOption numOption2("t", "The time argument", "number", "1");
    parser.addOption(numOption);
    parser.addOption(numOption2);
    parser.process(a);



    if(parser.isSet(numOption)){
        num = parser.value(numOption).toInt();
    }

    qDebug("Hello World version %d\n", num);


    return a.exec();
}
