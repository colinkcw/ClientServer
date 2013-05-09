
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
 *         &lt;element name="firstNum" type="{http://www.w3.org/2001/XMLSchema}int"/>
 *         &lt;element name="secondNum" type="{http://www.w3.org/2001/XMLSchema}int"/>
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
    "firstNum",
    "secondNum"
})
@XmlRootElement(name = "simpleMethod")
public class SimpleMethod {

    protected int firstNum;
    protected int secondNum;

    /**
     * Gets the value of the firstNum property.
     * 
     */
    public int getFirstNum() {
        return firstNum;
    }

    /**
     * Sets the value of the firstNum property.
     * 
     */
    public void setFirstNum(int value) {
        this.firstNum = value;
    }

    /**
     * Gets the value of the secondNum property.
     * 
     */
    public int getSecondNum() {
        return secondNum;
    }

    /**
     * Sets the value of the secondNum property.
     * 
     */
    public void setSecondNum(int value) {
        this.secondNum = value;
    }

}
