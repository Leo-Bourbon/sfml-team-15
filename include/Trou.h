#ifndef TROU_H
#define TROU_H


class Trou
{
    public:
        Trou();
        Trou(Vector2f position, Vector2f taille): Entite(Vector2f position, Vector2f taille);
        virtual ~Trou();

    protected:

    private:
};

#endif // TROU_H
