using System;
using System.Runtime.InteropServices;
namespace ANamespace 
{

  public interface ASignatures
  {
    
	int sum(int a, int b);
    
  }

  [ClassInterface(ClassInterfaceType.AutoDual)]
  public class AClass :ASignatures
  {
    
	public int sum(int a, int b)
	{
		int c = a + b;
		return c;
	}
  }
}