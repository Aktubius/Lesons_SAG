﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.1
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Client_WithSecurity.ServiceReference1 {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="ServiceReference1.ISamples")]
    public interface ISamples {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/ISamples/GetSecretCode", ReplyAction="http://tempuri.org/ISamples/GetSecretCodeResponse")]
        string GetSecretCode();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/ISamples/GetMemberCode", ReplyAction="http://tempuri.org/ISamples/GetMemberCodeResponse")]
        string GetMemberCode();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/ISamples/GetPublicCode", ReplyAction="http://tempuri.org/ISamples/GetPublicCodeResponse")]
        string GetPublicCode();
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface ISamplesChannel : Client_WithSecurity.ServiceReference1.ISamples, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class SamplesClient : System.ServiceModel.ClientBase<Client_WithSecurity.ServiceReference1.ISamples>, Client_WithSecurity.ServiceReference1.ISamples {
        
        public SamplesClient() {
        }
        
        public SamplesClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public SamplesClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public SamplesClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public SamplesClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public string GetSecretCode() {
            return base.Channel.GetSecretCode();
        }
        
        public string GetMemberCode() {
            return base.Channel.GetMemberCode();
        }
        
        public string GetPublicCode() {
            return base.Channel.GetPublicCode();
        }
    }
}
