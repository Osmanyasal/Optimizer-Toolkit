#ifndef OPTIMIZER_TOOLKIT__SRC__CORE__RENDER__BINDABLE_HH
#define OPTIMIZER_TOOLKIT__SRC__CORE__RENDER__BINDABLE_HH

namespace OPTKIT::core
{
    class Bindable
    {
    public:
        Bindable(){}
        virtual ~Bindable(){}
        
        virtual void bind() = 0;
        virtual void unbind()  = 0;
        virtual void destroy() = 0;
    };

} // namespace OPTKIT::core

#endif