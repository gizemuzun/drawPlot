#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


    void MainWindow::on_pushButton_Parabol_clicked()
    {
        //PARABOL ÇİZİMİ

        QVector<double> x(101), y(101); // initialize with entries 0..100

        for (int i=0; i<101; i++)
        {
            x[i] = i/50.0 -1;
            y[i] = 0.1 * x[i] * x[i];
        }

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(0)->setPen(QPen(Qt::green));
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

        // give the axes some labels:

        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");

        // set axes ranges, so we see all data:

        ui->customPlot->xAxis->setRange(-10, 10);
        ui->customPlot->yAxis->setRange(0, 1);
        ui->customPlot->replot();

    }


void MainWindow::on_pushButtonExponansiyel_clicked()
{
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::green));
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 128, 20))); // first graph will be filled with translucent blue
        //ui-> customPlot->addGraph();
        //ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
        // generate some points of data (y0 for first, y1 for second graph):
        QVector<double> x(250), y0(250), y1(250);
        for (int i=0; i<250; ++i)
        {
            x[i] = i;

            y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
            //y1[i] = qExp(-i/150.0);              // exponential envelope
        }
       //x ve y eksenlerindeki sayılar
        ui->customPlot->xAxis2->setVisible(true);
        ui->customPlot->xAxis2->setTickLabels(false);
        ui->customPlot->yAxis2->setVisible(true);
        ui->customPlot->yAxis2->setTickLabels(false);
        // make left and bottom axes always transfer their ranges to right and top axes:
        //connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
        //connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
        // graph(0) Exponansiyel grafik- graph(1) grafiğin exponansiyel azalmasını gösteren çizgi
         ui->customPlot->graph(0)->setData(x, y0);
        //Aşağıdaki kod üstel azalmayı gösteren çizgi
        //ui->customPlot->graph(1)->setData(x, y1);
        // skalayı alana mükemmel bir şekilde ayarlar
        ui->customPlot->graph(0)->rescaleAxes();

        //Tekerlek ile grafikteki alanı ayarlama alanı
        //ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->customPlot->replot();
    }


void MainWindow::on_pushButtonSin_clicked()
{   ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));

    QVector<double> x(250), y(250);
    for (int i=0;i<250 ;i++)
    {
        x[i] = i;
        y[i] =qSin  (i/40.0);

    }

    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->rescaleAxes();
    ui->customPlot->replot();


}

void MainWindow::on_pushButtonSquare_clicked()
{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::black));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));



    QVector<double> x (1000) , y(1000);
    for (int i=0; i<50 ; i++)


    {
        x[i] = i;
        y[i] = 0;

    }

    for (int i=50 ;i<100 ;i++)
    {
        x[i] = i;
        y[i] =1;
    }

    for (int i =100 ;i<150 ;i++)
    {
        x[i]=i;
        y[i] = 0;
    }

    for ( int i=150 ; i< 200; i++)
    {
        x[i] =i;
        y[i] = 1;
    }

    for ( int i=200 ; i< 250; i++)
    {
        x[i] =i;
        y[i] = 0;
    }

    for ( int i=250 ; i< 300; i++)
    {
        x[i] =i;
        y[i] = 1;
    }

    for ( int i=300 ; i< 350; i++)
    {
        x[i] =i;
        y[i] = 0;
    }

    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->rescaleAxes();

    //Tekerlek ile grafikteki alanı ayarlama alanı
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->replot();
}

void MainWindow::on_pushButtonLinear_clicked()
{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));
    QVector<double> x(250) , y(250);

    for (int i =100 ;i<150 ;i++)
    {
        x[i]=i;
        y[i] =i;
    }

    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->rescaleAxes();

    //Tekerlek ile grafikteki alanı ayarlama alanı
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



    ui->customPlot->replot();
}

void MainWindow::on_pushButtonTriangle_clicked()

{   ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));

    QVector<double> x(1000) , y(1000);


    for (int i =0 ; i< 100 ; i++)
    {
        x[i]=i;
        y[i] =i;
    }


    for (int i = 100;i< 200;i++) {

        x[i]=i;
        y[i]=200-i;
    }

    for (int i = 200; i < 300;i++) {

        x[i]=i;
        y[i]=i-200;
    }

    for (int i =300 ; i < 400; i++)
    {
        x[i] = i;
        y[i] = 400-i;
    }

    for (int i =400 ; i < 500; i++)
    {
        x[i] = i;
        y[i] = i-400;
    }

    for (int i = 500 ; i < 600; i++)
    {
        x[i] = i;
        y[i] = 600-i;
    }

    for (int i =600 ; i < 700; i++)
    {
        x[i] = i;
        y[i] = i-600;
    }

    for (int i =700 ; i < 800; i++)
    {
        x[i] = i;
        y[i] = 800-i;
    }

    for (int i =800 ; i < 900; i++)
    {
        x[i] = i;
        y[i] = i-800;
    }

    for (int i =900 ; i < 1000; i++)
    {
        x[i] = i;
        y[i] = 1000-i;
    }


    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->graph(0)->rescaleAxes();

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->replot();

}

void MainWindow::on_pushButtonSawTooth_clicked()

{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));

    QVector<double> x(1100) , y(1100);


    for (int i =0 ; i< 100 ; i++)
    {
        x[i]=i;
        y[i] =i;
    }
    for (int i =100 ; i< 200 ; i++)
    {
        x[i]=i;
        y[i] =i-100;
    }

    for (int i =200 ; i< 300 ; i++)
    {
        x[i]=i;
        y[i] =i-200;
    }

    for (int i =300 ; i< 400 ; i++)
    {
        x[i]=i;
        y[i] =i-300;
    }

    for (int i =400 ; i< 500 ; i++)
    {
        x[i]=i;
        y[i] =i-400;
    }

    for (int i =500 ; i< 600 ; i++)
    {
        x[i]=i;
        y[i] =i-500;
    }

    for (int i =600 ; i< 700 ; i++)
    {
        x[i]=i;
        y[i] =i-600;
    }

    for (int i =700 ; i< 800 ; i++)
    {
        x[i]=i;
        y[i] =i-700;
    }

    for (int i =800 ; i < 900 ; i++)
    {
        x[i]=i;
        y[i] =i-800;
    }

    for (int i =900 ; i < 1000; i++)
    {
        x[i] = i;
        y[i] = i-900;
    }

    for (int i =1000 ; i< 1100 ; i++)
    {
        x[i] = i;
        y[i] = i - 1000;
    }





    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->graph(0)->rescaleAxes();

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->replot();


}
