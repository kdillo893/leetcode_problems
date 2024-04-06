package com.kdill;

import org.junit.Test;
import static org.junit.Assert.*;

public class CodingBatTest {
    
    
    @Test
    public void endUpTest() {
        //check that the endup function uppercases the last 3 chars.
        
        String ts1 = "test1a";
        String rs1 = CodingBat.endUp(ts1);
        assertEquals("tesT1A", rs1);

        String ts2 = "ABc";
        String rs2 = CodingBat.endUp(ts2);
        assertEquals("ABC", rs2);

        String ts3 = "";
        String rs3 = CodingBat.endUp(ts3);
        assertEquals("", rs3);

        String ts4 = "This is a really Long String He.";
        String rs4 = CodingBat.endUp(ts4);
        assertEquals("This is a really Long String HE.", rs4);
    }

    //has between 1 and 3 e's in it.
    @Test
    public void stringETest() {
        String test1String = "Hello";
        assert(CodingBat.stringE(test1String));

        String test2String = "Hllo";
        assertFalse(CodingBat.stringE(test2String));

        String test3String = "Heeeeeeello";
        assertFalse(CodingBat.stringE(test3String));

        String test4String = "Hey0000e000llo";
        assert(CodingBat.stringE(test4String));

    }
}
