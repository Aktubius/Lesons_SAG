import javax.naming.InitialContext;
import javax.naming.Context;
import javax.rmi.PortableRemoteObject;

import com.calc.Calculator;
import com.calc.CalculatorHome;

import java.util.Properties;
import org.jnp.interfaces.*;

public class CalculatorClient{
	public static void main(String[] args){     
		
		Properties props = new Properties();

	//��������� ��� JNDI
	props.put(Context.INITIAL_CONTEXT_FACTORY, "org.jnp.interfaces.NamingContextFactory");
	props.put(Context.PROVIDER_URL, "localhost:1099");

	try{
		//������� ������� ��� ������, � ��������� ��
		//���������� ��� ������ ����� ����������� �� ������ localhost:1099
		InitialContext jndiContext = new InitialContext(props);
		System.out.println("1");

		//���������� ����� EJB ����������
		Object ref  = jndiContext.lookup("Calculator2");
		System.out.println("2");

		//�������� ������ �� ��� home-���������
		CalculatorHome home = (CalculatorHome)PortableRemoteObject.narrow(ref, CalculatorHome.class);

		//������� ������ Calculator � ������� home-����������
		Calculator calculator = home.create();
		int a = calculator.summ(10,10);

		System.out.println(a);
	}
	catch(Exception e){
		System.out.println(e.toString());
	}
	}
}