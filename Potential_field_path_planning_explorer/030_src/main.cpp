#include "mainwindow.h"
#include "surfacegraph.h"
#include <QtWidgets>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/Q3DBars>
#include <QHBoxLayout>
#include <QVBoxLayout>


using namespace QtDataVisualization;

int main(int argc, char *argv[])
{    
    QApplication app(argc, argv);
    Q3DSurface *graph = new Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);

    if(!graph->hasContext())
    {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGl context.");
        msgBox.exec();
        return -1;
    }
    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(static_cast<int>(screenSize.width()/1.6f),
                                    static_cast<int>(screenSize.height()/ 1.6f)));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    QWidget *window = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(window);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container,1);
    hLayout->addLayout(vLayout);
    vLayout->setAlignment(Qt::AlignTop);

    window->setWindowTitle(QStringLiteral("Surface Example"));

    SurfaceGraph *modifier = new SurfaceGraph(graph);
    modifier->enableModel(true);
    window->show();
    return app.exec();
}
