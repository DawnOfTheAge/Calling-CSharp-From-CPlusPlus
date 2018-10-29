#include "stdafx.h"
#using "C:\Projects\C++\CS From CPP\CS From CPP\CS.ContextDataManager\CS.ContextDataManager\bin\Debug\CS.ContextDataManager.dll"

#include <msclr\auto_gcroot.h>

using namespace System::Runtime::InteropServices; // Marshal

class ContextDataManagerWrapperPrivate
{
    public: msclr::auto_gcroot<ContextDataManager^> contextDataManager;
};

class __declspec(dllexport) ContextDataManagerWrapper
{
    private: ContextDataManagerWrapperPrivate* _private;

    public: ContextDataManagerWrapper()
    {
        _private = new ContextDataManagerWrapperPrivate();
        _private->contextDataManager = gcnew ContextDataManager();
    }

	public: const char** GetContextData(const char* contextData)
	{
		cli::array<System::String^>^ managedValues = _private->contextDataManager->GetContextData(gcnew System::String(contextData));

        const char** unmanagedValues = new const char*[managedValues->Length];
        
        for (int i = 0; i < managedValues->Length; ++i)
        {
            unmanagedValues[i] = (const char*)Marshal::StringToHGlobalAnsi(managedValues[i]).ToPointer();
        }
        
        return unmanagedValues;
	}

    public: ~ContextDataManagerWrapper()
    {
        delete _private;
    }
};