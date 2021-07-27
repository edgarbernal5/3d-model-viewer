#ifndef SCENERENDERER_H
#define SCENERENDERER_H

class SceneRenderer
{
public:
    virtual void renderAll() = 0;
    virtual void drawAxis() = 0;
};

#endif // SCENERENDERER_H
