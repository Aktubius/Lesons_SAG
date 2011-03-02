﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.1
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace ConverterClient.ConverterServiceReference {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="ConverterServiceReference.IParrotToPythonConverter")]
    public interface IParrotToPythonConverter {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IParrotToPythonConverter/ConvertParrotsToPythons", ReplyAction="http://tempuri.org/IParrotToPythonConverter/ConvertParrotsToPythonsResponse")]
        double ConvertParrotsToPythons(double parrots);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IParrotToPythonConverter/ConvertPythonsToParrots", ReplyAction="http://tempuri.org/IParrotToPythonConverter/ConvertPythonsToParrotsResponse")]
        double ConvertPythonsToParrots(double pythons);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IParrotToPythonConverterChannel : ConverterClient.ConverterServiceReference.IParrotToPythonConverter, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class ParrotToPythonConverterClient : System.ServiceModel.ClientBase<ConverterClient.ConverterServiceReference.IParrotToPythonConverter>, ConverterClient.ConverterServiceReference.IParrotToPythonConverter {
        
        public ParrotToPythonConverterClient() {
        }
        
        public ParrotToPythonConverterClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public ParrotToPythonConverterClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public ParrotToPythonConverterClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public ParrotToPythonConverterClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public double ConvertParrotsToPythons(double parrots) {
            return base.Channel.ConvertParrotsToPythons(parrots);
        }
        
        public double ConvertPythonsToParrots(double pythons) {
            return base.Channel.ConvertPythonsToParrots(pythons);
        }
    }
}