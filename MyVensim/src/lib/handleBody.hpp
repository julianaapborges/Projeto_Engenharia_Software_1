/**
 @file handleBody.hpp
 @brief Definição das classes Handle e Body para o padrão de projeto ponte (bridge).
 @author Juliana Aparecida Borges
 @date 2026-01-10
*/

#if ! defined( HANDLE_BODY )
#define HANDLE_BODY

/** @brief
 *
 * As classes Handle e Body implementam o padrão de projeto "bridge" (também conhecido como
 * "handle/body").
 * */
template <class T> 
class Handle
{

public: 

    // construtor
    Handle<T>( ){  
        pImpl_ = new T; 
        pImpl_->attach();  
    }
    
    /// Destrutor
    virtual ~Handle<T>(){ pImpl_->detach();     }

    // copy construtor 
    Handle<T>( const Handle& hd ):pImpl_( hd.pImpl_ ) { pImpl_->attach();  }

    // assignment operator
    Handle<T>& operator=( const Handle& hd) {
        if (  this != &hd )
        {
            hd.pImpl_->attach();
            pImpl_->detach();   
            pImpl_  = hd.pImpl_;
        }
        return *this;
    }
protected:

    /// referência para a implementação
    T *pImpl_; 
};

/**
 * @brief
 * * A classe Body foi implementada com base na classe teCounted escrita por Ricardo Cartaxo 
 * e Gilberto Câmara e encontrada na biblioteca geográfica TerraLib.
 */

class Body
{   
public:
    // Construtor: zero referências quando o objeto está sendo construído
    Body(): refCount_ ( 0 ){  }
    

    // Aumenta o número de referências a este objeto
    void attach ()  { refCount_++; }

    // Diminui o número de referências a este objeto
    // Destrói-o se não houver mais referências a ele
    void detach (){ 
        if ( --refCount_ == 0 ) { 
            delete this; 
        }
    }

    // Returna o número de referências a este objeto
    int refCount(){ return refCount_; }

    // Destrutor
    virtual ~Body(){}

private:

    // Não é permitida a cópia
    Body(const Body&);

    // Implementação
    Body& operator=(const Body&){return *this;}

    int refCount_;  // o número de referências a esta classe

};

#endif