package DBMS_Demo.ExcelSheets;

import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

//import java.io.FileInputStream;
//import java.io.IOException;
import java.io.*;
import java.util.*;

public class ReadWriteXExcel {
	public static void readExcelSheet(String filePath) {
		try (FileInputStream fis = new FileInputStream(filePath);
	             Workbook workbook = new XSSFWorkbook(fis)) { //if you declare inside the try then no need to close the fis & workbook externally it will be automatically closed

	            Sheet sheet = workbook.getSheetAt(0); // Get the first sheet
	            for (Row row : sheet) {
	                for (Cell cell : row) {
	                    switch (cell.getCellType()) {
	                        case STRING:
	                            System.out.print(cell.getStringCellValue() + "\t");
	                            break;
	                        case NUMERIC:
	                            System.out.print(cell.getNumericCellValue() + "\t");
	                            break;
	                        case BOOLEAN:
	                            System.out.print(cell.getBooleanCellValue() + "\t");
	                            break;
	                        default:
	                            System.out.print("UNKNOWN\t");
	                            break;
	                    }
	                }
	                System.out.println();
	            }

	        } catch (IOException e) {
	            e.printStackTrace();
	        }

	}
	//Appending the file
	public static void appendFile(String filePath) {
		try (FileInputStream fis = new FileInputStream(filePath);
	             Workbook workbook = new XSSFWorkbook(fis)) {

	            // Access the existing sheet or create a new one if it doesn't exist
	            Sheet sheet = workbook.getSheetAt(0); // Use the first sheet

	            // Determine the next row index (one after the last row)
	            int nextRowIndex = sheet.getLastRowNum() + 1;

	            // Create a new row
	            Row newRow = sheet.createRow(nextRowIndex);

	            // Create new cells and set values
//	            Cell cell1 = newRow.createCell(0);
//	            Cell cell2 = newRow.createCell(1);
	            Scanner sc = new Scanner(System.in);
	            int columnsCount = sheet.getRow(1).getLastCellNum();
	            for(int i=0; i<columnsCount; i++) {
	            	Cell cell = newRow.createCell(i);
	            	System.out.println("Enter the " + (i+1) + " cell value");
	            	cell.setCellValue(sc.next());
	            }

	            // Write the changes to the file
	            try (FileOutputStream fos = new FileOutputStream(filePath)) {
	                workbook.write(fos);
	            }

	        } catch (IOException e) {
	            e.printStackTrace();
	        }
	 
	}
	
	public static void main(String[] args) {
        String filePath = "D:\\Github\\DBMS Assignment\\Book1.xlsx"; // Path to your Excel file
        readExcelSheet(filePath);
        appendFile(filePath);
	}
}
