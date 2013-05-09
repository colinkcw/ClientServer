
package org.tempuri;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for anonymous complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType>
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="simpleMethodResult" type="{http://www.w3.org/2001/XMLSchema}int"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "", propOrder = {
    "simpleMethodResult"
})
@XmlRootElement(name = "simpleMethodResponse")
public class SimpleMethodResponse {

    protected int simpleMethodResult;

    /**
     * Gets the value of the simpleMethodResult property.
     * 
     */
    public int getSimpleMethodResult() {
        return simpleMethodResult;
    }

    /**
     * Sets the value of the simpleMethodResult property.
     * 
     */
    public void setSimpleMethodResult(int value) {
        this.simpleMethodResult = value;
    }

}
