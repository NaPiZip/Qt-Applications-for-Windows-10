#include "surfacegraph.h"
#include <QtMath>
using namespace QtDataVisualization;

SurfaceGraph::SurfaceGraph(QtDataVisualization::Q3DSurface *surface) :
    m_graph(surface),
    m_sqrtSinProxy{new QSurfaceDataProxy()},
    m_sqrtSinSeries{new QSurface3DSeries(m_sqrtSinProxy)}
{
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->setAxisY(new QValue3DAxis);
    m_graph->setAxisZ(new QValue3DAxis);

    m_sqrtSinProxy = new QSurfaceDataProxy;
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
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountZ);
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

void SurfaceGraph::enableHeightMapModel(bool enable)
{
    if(enable)
    {
        m_sqrtSinSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        m_sqrtSinSeries->setFlatShadingEnabled(true);

        m_graph->axisX()->setLabelFormat("%.1f N");
        m_graph->axisY()->setLabelFormat("%.1f E");
        m_graph->axisX()->setRange(34.0f, 40.0f);
        m_graph->axisY()->setAutoAdjustRange(true);
        m_graph->axisZ()->setRange(18.0f, 24.0f);

        m_graph->axisY()->setTitle(QStringLiteral("Height"));
        m_graph->axisZ()->setTitle(QStringLiteral("Longitude"));

        m_graph->axisX()->setTitle(QStringLiteral("Latitude"));
        m_graph->axisY()->setTitle(QStringLiteral("Height"));
        m_graph->axisZ()->setTitle(QStringLiteral("Longitude"));

        m_graph->addSeries(m_sqrtSinSeries);
      }
}
