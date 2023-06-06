package basics;

/*
Idea: serialize = put into a data stream (bytes for example) for the purpose of transmitting serially to
another application.

an object can be put into a bytestream and, if the application is expecting an object of a certain type,
that bytestream can be converted back into the appropriate object for processing.
 */

import java.io.Serial;
import java.io.Serializable;

public class SerializedCar implements Serializable {

    @Serial
    private static final long serialVersionUID = 1L;

    private long modelNo;
    private String modelName;
    private int year;
    private long currentMileage;

    public SerializedCar(long modelNo, String modelName, int year, long currentMileage) {
        this.modelNo = modelNo;
        this.modelName = modelName;
        this.year = year;
        this.currentMileage = currentMileage;
    }

    //setters and getters
    public long getModelNo() {
        return modelNo;
    }

    public void setModelNo(long modelNo) {
        this.modelNo = modelNo;
    }

    public String getModelName() {
        return modelName;
    }

    public void setModelName(String modelName) {
        this.modelName = modelName;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public long getCurrentMileage() {
        return currentMileage;
    }

    public void setCurrentMileage(long currentMileage) {
        this.currentMileage = currentMileage;
    }

    @Override
    public String toString() {
        return "SerializedCar{" +
                "modelNo=" + modelNo +
                ", modelName='" + modelName + '\'' +
                ", year=" + year +
                ", currentMileage=" + currentMileage +
                '}';
    }
}
