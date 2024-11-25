package com.sheikhdipta003.footballdb.data;

import java.io.Serializable;

public class Player implements Serializable{
    private String Name;
    private String Country;
    private String Club;
    private String Position;    //"Goalkeeper", "Defender", "Midfielder" or "Forward"
    private int Age;    //in years
    private int Number;
    private double Height;  //in meters
    private double WeeklySalary;
    private double Price;

    public double getWeeklySalary() {
        return WeeklySalary;
    }

    public double getHeight() {
        return Height;
    }

    public int getAge() {
        return Age;
    }

    public int getNumber() {
        return Number;
    }

    public String getClub() {
        return Club;
    }

    public String getCountry() {
        return Country;
    }

    public String getName() {
        return Name;
    }

    public String getPosition() {
        return Position;
    }

    public double getPrice() {
        return Price;
    }

    public void setAge(int age) {
        Age = age;
    }

    public void setName(String name) {
        Name = name;
    }

    public void setClub(String club) {
        Club = club;
    }

    public void setCountry(String country) {
        Country = country;
    }

    public void setHeight(double height) {
        Height = height;
    }

    public void setNumber(int number) {
        Number = number;
    }

    public void setPosition(String position) {
        Position = position;
    }

    public void setWeeklySalary(double weeklySalary) {
        WeeklySalary = weeklySalary;
    }

    public void setPrice(double Price) {
        this.Price = Price;
    }

    public String showPlayerInfo(){
        return (Name + "," + Country + "," + Age + "," + Height + "," + Club + "," + Position + "," + Number + "," + WeeklySalary + "," + Price);
    }
}
