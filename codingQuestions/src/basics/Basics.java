package basics;
/*
  Kevin Dillon.

  Aggregation of coding questions and my logic when working through them.
 */

public class Basics {

    public static void main(String[] args){

        UsingEnum();

        Annotations ann = new Annotations();
        ann.randomMethod();
    }

    public String queue() {



        return MyImplementation.queue();
    }

    //Learning enums...
    //enum is a defined value; can set them and use some constructor which are internal to an enum

    public enum Day {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    }

    enum Color {
        RED("red"), GREEN("green"), BLUE("blue");

        private final String value;

        Color(String value) {
            this.value = value;
        }

        public String getValue () {
            return this.value;
        }
    }

    //using the above enum:
    public static void  UsingEnum() {
        Color col1 = Color.RED;

        System.out.println("Red enum name: " + col1.name());
        System.out.println("Red enum name: " + col1.getValue());

        for (Color color : Color.values()) {
            System.out.println("Enum value: " + color.name());
        }
    }
}
