#ifndef MONOMIOINTERFAZ_HPP
#define MONOMIOINTERFAZ_HPP
namespace ed {

    class MonomioInterfaz {
    public:

        virtual float getCoeficiente() const = 0;

        virtual int getGrado() const = 0;

        virtual void setCoeficiente(float coeficiente) = 0;

        virtual void setGrado(int grado) = 0;

    }; // Fin clase

} // Fin namespace

#endif
