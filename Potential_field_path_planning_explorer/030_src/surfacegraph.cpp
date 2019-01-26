#include "surfacegraph.h"
#include <QtDebug>
#include <QtMath>
using namespace QtDataVisualization;

SurfaceGraph::SurfaceGraph(QtDataVisualization::Q3DSurface *surface) :
    m_graph(surface)
{
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->axisX()->setTitleVisible(true);
    m_graph->setAxisY(new QValue3DAxis);    
    m_graph->axisY()->setTitleVisible(true);
    m_graph->setAxisZ(new QValue3DAxis);    
    m_graph->axisZ()->setTitleVisible(true);
    m_graph->setFlags( Qt::WindowSystemMenuHint | Qt::WindowSystemMenuHint);

    m_sqrtSinProxy = new QSurfaceDataProxy();
    m_sqrtSinSeries = new QSurface3DSeries(m_sqrtSinProxy);
    fillSqrtSinProxy();
}

void SurfaceGraph::fillSqrtSinProxy()
{
    float stepX = (sampleMax - sampleMin) / static_cast<float>(sampleCountX -1);
    float stepZ = (sampleMax - sampleMin) / static_cast<float>(sampleCountZ -1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray();
    dataArray->reserve(sampleCountZ);

    for(int i = 0; i < sampleCountZ; i++)
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
        float z = qMin(sampleMax, (i * stepZ + sampleMin));
        int index = 0;
        for(int j = 0; j < sampleCountX; j++)
        {
            float x = qMin(sampleMax, (j * stepX + sampleMin)),
                  R = qSqrt(z * z + x * x) * 0.01f,
                  y = (qSin(R) / R + 0.24f) * 1.61f;
            (*newRow)[index++].setPosition(QVector3D(x ,y, z));
        }
        *dataArray << newRow;
    }
    m_sqrtSinProxy->resetArray(dataArray);
}

SurfaceGraph::~SurfaceGraph()
{
    delete m_graph;
}

void SurfaceGraph::enableModel(bool enable)
{
    if(enable)
    {
        qDebug()<< "Number of rows: "  << m_sqrtSinProxy->rowCount()
                << "Number of cols: "  << m_sqrtSinProxy->columnCount();

        m_sqrtSinSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        m_sqrtSinSeries->setFlatShadingEnabled(true);

        m_graph->axisX()->setLabelFormat("%.2f");
        m_graph->axisZ()->setLabelFormat("%.2f");

        m_graph->axisX()->setLabelAutoRotation(30);
        m_graph->axisY()->setLabelAutoRotation(90);
        m_graph->axisZ()->setLabelAutoRotation(30);

        m_graph->axisX()->setTitle(QStringLiteral("X Values"));
        m_graph->axisY()->setTitle(QStringLiteral("Y Values"));
        m_graph->axisZ()->setTitle(QStringLiteral("Z Values"));
        m_graph->setTitle("Sine function");

        m_graph->addSeries(m_sqrtSinSeries);
      }
}
