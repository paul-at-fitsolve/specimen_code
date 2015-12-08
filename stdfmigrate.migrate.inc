<?php
/**
 * Implements hook_migrate_api().
 */
function stdfmigrate_migrate_api() {
  return array(
    'api' => 2, 
    'groups' => array(
      'projects' => array(
        'title' => t('Projects')
      ), 
      'virtual_library' => array(
        'title' => t('Virtual Library')
      )
    ), 
    'migrations' => array(
      'VirtualLibraryFile' => array(
        'class_name' => 'StdfMigrationVirtualLibraryMigration', 
        'group_name' => 'virtual_library'
      ), 
      'PublisherEN' => array(
        'class_name' => 'StdfMigrationPublisherMigration', 
        'group_name' => 'virtual_library'
      ), 
      
      'ProjectNode' => array(
        'class_name' => 'StdfMigrationProjectMigration', 
        'group_name' => 'projects'
      )
    )
  );
}