<?php
/**
 * @file
 */

/**
 * Class StdfMigration
 *
 * Base class describing the client virtual library metadata.
 */
abstract class StdfMigration extends Migration {
  protected $project_source_file;
  protected $virtual_library_source_file;
  protected $publishers_source_file;
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->team = array(
      new MigrateTeamMember('Steven Tanner', 'steve.tanner@wto.org', t('Product Owner')), 
      new MigrateTeamMember('Paul Wilkin', 'paulw@appnovation.com', t('Implementor'))
    );
    $this->project_source_file = drupal_get_path('module', 'stdfmigrate') . '/stdfprojects.csv';
    $this->virtual_library_source_file = drupal_get_path('module', 'stdfmigrate') . '/stdfvlibraryfile.csv';
    $this->publishers_source_file = drupal_get_path('module', 'stdfmigrate') . '/publishers.csv';
  }
  protected function publisherscolumns() {
    $columns[0] = array(
      'ref', 
      'Reference ID'
    );
    
    $columns[1] = array(
      'publisher', 
      'Publisher'
    );
    
    return $columns;
  }
  protected function vlibrarycsvcolumns() {
    $columns[0] = array(
      'ref', 
      'Reference ID'
    );
    $columns[1] = array(
      'title', 
      'Title'
    );
    
    $columns[2] = array(
      'pub_date', 
      'Publicationdate'
    );
    $columns[3] = array(
      'authors', 
      'Authors'
    );
    $columns[4] = array(
      'publisher_en', 
      'Publisher EN'
    );
    
    $columns[5] = array(
      'publisher_fr', 
      'Publisher FR'
    );
    
    $columns[6] = array(
      'publisher_es', 
      'Publisher ES'
    );
    $columns[7] = array(
      'country_en', 
      'Country EN'
    );
    
    $columns[8] = array(
      'country_fr', 
      'Country FR'
    );
    
    $columns[9] = array(
      'country_sp', 
      'Country SP'
    );
    
    $columns[10] = array(
      'language', 
      'Language'
    );
    
    $columns[11] = array(
      'filename', 
      'Filename'
    );
    
    return $columns;
  }
  protected function projectcsvcolumns() {
    $columns[0] = array(
      'reference_number', 
      'Reference Number'
    );
    $columns[1] = array(
      'responsible', 
      'Responsible'
    );
    $columns[2] = array(
      'previous_responsible', 
      'Previous Responsible'
    );
    $columns[3] = array(
      'accounting_code', 
      'Accounting Code'
    );
    $columns[4] = array(
      'type', 
      'Type'
    );
    $columns[5] = array(
      'status', 
      'Status'
    );
    $columns[6] = array(
      'ppg_outcome', 
      'PPG Outcome'
    );
    $columns[7] = array(
      'title', 
      'Title'
    );
    $columns[8] = array(
      'objective', 
      'Objective'
    );
    $columns[9] = array(
      'beneficiary', 
      'Beneficiary'
    );
    $columns[10] = array(
      'region', 
      'Region'
    );
    $columns[11] = array(
      'dac', 
      'Dac'
    );
    $columns[12] = array(
      'acp', 
      'Acp'
    );
    $columns[13] = array(
      'sector', 
      'Sector'
    );
    $columns[14] = array(
      'implementing_entity', 
      'Implementing Entity'
    );
    $columns[15] = array(
      'partners', 
      'partners'
    );
    $columns[16] = array(
      'approval_date', 
      'Approval Date'
    );
    $columns[17] = array(
      'approval_year', 
      'Approval Year'
    );
    $columns[18] = array(
      'start_date', 
      'Start Date'
    );
    $columns[19] = array(
      'start_year', 
      'Start Year'
    );
    $columns[20] = array(
      'end_date', 
      'End Date'
    );
    $columns[21] = array(
      'extension', 
      'Extension'
    );
    $columns[22] = array(
      'actual_end_date', 
      'Actual End Date'
    );
    $columns[23] = array(
      'end_year', 
      'End Year'
    );
    $columns[24] = array(
      'actions_since', 
      'Actions Since Last WG'
    );
    $columns[25] = array(
      'actions_required', 
      'Actions Required'
    );
    $columns[26] = array(
      'total_stdf', 
      'Total STDF'
    );
    $columns[27] = array(
      'implementation_budget', 
      'Implementation Budget'
    );
    $columns[28] = array(
      'overhead', 
      'Overhead'
    );
    $columns[29] = array(
      'non_stdf_contribution', 
      'Non STDF Contribution'
    );
    $columns[30] = array(
      'total_project_value', 
      'Total Project Value'
    );
    $columns[31] = array(
      'budget_eur', 
      'Budget EUR'
    );
    $columns[32] = array(
      'budget_chf', 
      'Budget CHF'
    );
    $columns[33] = array(
      'comments', 
      'Comments'
    );
    $columns[34] = array(
      'link1', 
      'Link 1'
    );
    $columns[35] = array(
      'link2', 
      'Link 2'
    );
    $columns[36] = array(
      'link3', 
      'Link 3'
    );
    $columns[37] = array(
      'link4', 
      'Link 4'
    );
    $columns[38] = array(
      'link5', 
      'Link 5'
    );
    $columns[39] = array(
      'link6', 
      'Link 6'
    );
    $columns[40] = array(
      'link7', 
      'Link 7'
    );
    $columns[41] = array(
      'link8', 
      'Link 8'
    );
    $columns[42] = array(
      'link9', 
      'Link 9'
    );
    $columns[43] = array(
      'link10', 
      'Link 10'
    );
    
    return $columns;
  }
}