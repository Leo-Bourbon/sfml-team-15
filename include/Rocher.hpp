#ifndef ROCHER_HPP_INCLUDED
#define ROCHER_HPP_INCLUDED


class Rocher : public Entite
{
    public:
        Rocher();
        Rocher(Vector2f position, Vector2f taille): Entite(Vector2f position, Vector2f taille);
        virtual ~Rocher();

    protected:

    private:
};

#endif // ROCHER_HPP_INCLUDED
