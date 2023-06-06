package basics;

//Annotations - this is how java compilation provides additional information without needing to repeat.
//example annotations are @SpringController, @Override, @SuppressWarnings etc...

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

//Marker annotation -> an annotation which provides no additional instruction for how to process...
//@Retention(RetentionPolicy.RUNTIME)
//@Target(ElementType.TYPE)
//public @interface MarkerAnnotation {
//    //nothing in here?
//}

//A functional annotation:
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface AnnotationExample {
    int value();
}