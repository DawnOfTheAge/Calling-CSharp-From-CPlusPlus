using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class ContextDataManager
{
    public string[] GetContextData(string contextData)
    {
        Console.WriteLine("[C# Lib]: Got[" + contextData + "]");

        return contextData.Split(':');
    }
}

