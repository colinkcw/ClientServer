package com.exchangeservice;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
 
public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
      private static String SOAP_ACTION1 = "http://tempuri.org/exchangeRate";
      private static String NAMESPACE = "http://tempuri.org/";
      private static String METHOD_NAME1 = "exchangeRate";
      private static String URL = "http://10.0.2.2/exchangeRate/Service1.asmx?WSDL";
 
      Button btnCalc;
      EditText txtCountry,txtAmount,txtResult;

     
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
       
        btnCalc = (Button)findViewById(R.id.btnCalc);
        txtCountry = (EditText)findViewById(R.id.txtCountry);
        txtAmount = (EditText)findViewById(R.id.txtAmount);
        txtResult = (EditText)findViewById(R.id.txtResult);
       
        btnCalc.setOnClickListener(new View.OnClickListener()
        {
                  @Override
                  public void onClick(View v)
                  {
                	 
                	  int amount = 0;
                	  String country;
                	  
                        //soap request + add parameters
                  SoapObject request = new SoapObject(NAMESPACE, METHOD_NAME1);       
                 
                  //Use this to add parameters
                  amount = Integer.parseInt(txtAmount.getText().toString());
                  country = txtCountry.getText().toString();
                  request.addProperty("amount",amount);
                  request.addProperty("country",country);
                  
                  //txtResult.setText(amount + " " + country);
                  //Declare the version of the SOAP request
                  SoapSerializationEnvelope envelope = new SoapSerializationEnvelope(SoapEnvelope.VER11);
                 
                  envelope.setOutputSoapObject(request);
                  envelope.dotNet = true;
                 
                  try {
                        HttpTransportSE androidHttpTransport = new HttpTransportSE(URL);
                       
                        //this is the actual part that will call the webservice
                        androidHttpTransport.call(SOAP_ACTION1, envelope);
                       
                        // Get the SoapResult from the envelope body.
                        SoapObject result = (SoapObject)envelope.bodyIn;
 
                        if(result != null)
                        {
                              //Get the first property and change the label text
                              txtResult.setText(result.getProperty(0).toString());
                        }
                        else
                        {
                              Toast.makeText(getApplicationContext(), "No Response",Toast.LENGTH_LONG).show();
                        }
                  } catch (Exception e) {
                        e.printStackTrace();
                  }
                  }
            });
       
    }
}