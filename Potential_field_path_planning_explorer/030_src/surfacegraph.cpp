#include "surfacegraph.h"
#include <QtMath>
using namespace QtDataVisualization;

SurfaceGraph::SurfaceGraph(QObject *parent) : QObject(parent),
    m_sqrtSinProxy{new QSurfaceDataProxy()},
    m_sqrtSinSeries{new QSurface3DSeries(m_sqrtSinProxy)}
{

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
