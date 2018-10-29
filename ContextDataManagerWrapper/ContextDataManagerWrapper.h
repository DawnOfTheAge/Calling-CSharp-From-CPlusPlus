class ContextDataManagerWrapperPrivate;

class ContextDataManagerWrapper
{
    private: ContextDataManagerWrapperPrivate* _private;

    public: ContextDataManagerWrapper();
    
	public: const char** GetContextData(const char* contextData);
};
