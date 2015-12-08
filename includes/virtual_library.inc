<?php
/**
 * @file
 */

/**
 * Class StdfMigrationVirtualLibraryMigration
 *
 * Class describing the client virtual library metadata.
 */
class StdfMigrationVirtualLibraryMigration extends StdfMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import virtual library from CSV.');
    $this->systemOfRecord = Migration::SOURCE;
    $this->source = new MigrateSourceCSV($this->virtual_library_source_file, $this->vlibrarycsvcolumns(), array(
      'header_rows' => 1
    ));
    $this->destination = new MigrateDestinationFile('virtual_library_document');
    
    $this->map = new MigrateSQLMap($this->machineName, array(
      'ref' => array(
        'type' => 'int', 
        'unsigned' => TRUE, 
        'not null' => TRUE, 
        'description' => 'Reference ID'
      )
    ), MigrateDestinationFile::getKeySchema());
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('value', 'filename');
    
    $this->addFieldMapping('field_publication_date', 'pub_date');
    
    $this->addFieldMapping('field_publisher', 'publisher_en')->separator(';');
    $this->addFieldMapping('field_publisher:create_term')->defaultValue(TRUE);
    
    $this->addFieldMapping('field_language', 'language');
    
    $this->addFieldMapping('field_author', 'authors')->separator(';');
    $this->addFieldMapping('field_author:create_term')->defaultValue(TRUE);
    
    $this->addFieldMapping('field_country', 'country_en')->separator(';');
    $this->addFieldMapping('field_country:create_term')->defaultValue(TRUE);
    
    $source_dir = drupal_get_path('module', 'stdfmigrate') . '/virtual_library';
    
    $this->addFieldMapping('source_dir')->defaultValue($source_dir);
    
    $unmigrated = array(
      'uid', 
      'timestamp', 
      'field_publisher:source_type', 
      'field_publisher:ignore_case', 
      'field_author:source_type', 
      'field_author:ignore_case', 
      'field_country:source_type', 
      'field_country:ignore_case', 
      'path', 
      'preserve_files', 
      'destination_dir', 
      'destination_file', 
      'file_replace', 
      'urlencode'
    );
    
    $this->addUnmigratedDestinations($unmigrated, t('Do Not Migrate'));
  }
  function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->authors = mb_convert_encoding($row->authors, 'UTF-8', 'Windows-1252');
    
    $row->publisher_fr = mb_convert_encoding($row->publisher_fr, 'UTF-8', 'Windows-1252');
    $row->publisher_es = mb_convert_encoding($row->publisher_es, 'UTF-8', 'Windows-1252');
    
    $row->country_fr = mb_convert_encoding($row->country_fr, 'UTF-8', 'Windows-1252');
    $row->country_es = mb_convert_encoding($row->country_es, 'UTF-8', 'Windows-1252');
    
    // Concatenate the English, French and Spanish spellings of publishers and countries.
    if ($row->publisher_fr != '' && $row->publisher_fr != $row->publisher_en) {
      $mystring = $row->publisher_en . ';' . $row->publisher_fr;
      $row->publisher_en .= ';' . $row->publisher_fr;
    }
    
    if ($row->publisher_es != '' && $row->publisher_es != $row->publisher_en) {
      $row->publisher_en .= ';' . $row->publisher_es;
    }
    
    if ($row->country_fr != '' && $row->country_fr != $row->country_en) {
      $mystring = $row->country_en . ';' . $row->country_fr;
      $row->country_en .= ';' . $row->country_fr;
    }
    
    if ($row->country_es != '' && $row->country_es != $row->country_en) {
      $row->country_en .= ';' . $row->country_es;
    }
    
    // Don't let PHP return HH:MM from the year - 2013 is nearly quarter past eight!
    // The "Year (and just the year)" format only works if a time string has already been found -- otherwise this format is recognised as HH MM.
    $row->pub_date = $row->pub_date . '/01/01';
    $row->pub_date = strtotime($row->pub_date);
    
    // We need to make sure the language code is in lower case to map onto the defined language codes.
    $row->language = strtolower($row->language);
  }
}