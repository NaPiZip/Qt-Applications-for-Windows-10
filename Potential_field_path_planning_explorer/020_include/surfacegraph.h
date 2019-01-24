#ifndef SURFACEGRAPH_H
#define SURFACEGRAPH_H

#include <QObject>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/Q3DSurface>

class SurfaceGraph : public QObject
{
    Q_OBJECT
public:
    explicit SurfaceGraph(QtDataVisualization::Q3DSurface *surface);
    ~SurfaceGraph();
    void fillSqrtSinProxy();
    void enableHeightMapModel(bool enable);

signals:

public slots:

private:
    constexpr static float sampleMin = -8.0f;
    constexpr static float sampleMax =  8.0f;
    constexpr static int sampleCountX = 50;
    constexpr static int sampleCountZ = 50;
    constexpr static int heightMapGridStepX = 6;
    constexpr static int heightMapGridStepZ = 6;

    QtDataVisualization::Q3DSurface *m_graph = nullptr;
    QtDataVisualization::QSurfaceDataProxy *m_sqrtSinProxy = nullptr;
    QtDataVisualization::QSurface3DSeries *m_sqrtSinSeries = nullptr;

};

#endif // SURFACEGRAPH_H
