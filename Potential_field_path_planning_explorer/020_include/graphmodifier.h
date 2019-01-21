#ifndef GRAPHMODIFIER_H
#define GRAPHMODIFIER_H

#include <QObject>
#include <QtDataVisualization/Q3DSurface>


using namespace QtDataVisualization;


class GraphModifier : public QObject
{
    Q_OBJECT
public:
    explicit GraphModifier(Q3DSurface *surfaceGraph);

};






#endif // GRAPHMODIFIER_H
