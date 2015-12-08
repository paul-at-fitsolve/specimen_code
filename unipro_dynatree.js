/**
 * 
 */
Drupal.Unipro.Dynatree = {};


jQuery.extend(Drupal.Unipro.Dynatree,{
  selectedNodes : {}, //Holds the selected nodes object.
  selectedKeys : [],// Holds an array of all the selected tree elements (mlocations). 
  dynaTree : {},
  //Function to submit the selected values to the server so that they can be saved against the node.
  submitDynatree : function() {
    Drupal.Unipro.Dynatree.dynaTree = jQuery('#tree').dynatree('getTree').toDict();
    Drupal.Unipro.Dynatree.parseChildren(Drupal.Unipro.Dynatree.dynaTree.children);
    jQuery.ajax({
      url : Drupal.settings.basePath + 'ajax/setmlocations',
      data: {
        mlocations : Drupal.Unipro.Dynatree.selectedKeys
      },
      async: false
    });
    return true;
  },
  //Function to recursively search through a tree and find all the selections at any level.
  parseChildren : function(child){
    for (var i = 0; i < child.length; i++){
      if(child[i].select){
        Drupal.Unipro.Dynatree.selectedKeys.push(child[i].key);	
      }
      if (child[i].children){
        Drupal.Unipro.Dynatree.parseChildren(child[i].children);
      }
    }
  }
});

jQuery(document).ready(function() {
  //All the configuration settings for the tree.

  jQuery('#tree').dynatree({
    checkbox: true,
    selectMode: 2, //Allows children and parents to be set independently, not via inheritence.
    activeVisible : true,
    autoFocus : false, // Stops auto focus which makes the browser scroll down the page to the Dynatree.
    initAjax: {
      url: Drupal.settings.basePath + "ajax/getmlocations", //The ajax callback which send the required data to construct the tree.
      data: {
        nid: Drupal.settings.currentNode
      }
    }, //The node id sent as a parameter with the ajax request.
    onPostInit: function( isReloading, isError) {
      var tree = jQuery('#tree').dynatree('getTree');
      
      //Takes the currentTid and uses this to select the appropriate node in the tree.
      if(Drupal.settings.currentTid != null){
        var node = tree.getNodeByKey(Drupal.settings.currentTid);
        node.select(); // Sets the current mlocations on in the Dynatree so that the user can see what the current mlocations are.
      } 
      var selectedNodes = tree.getSelectedNodes();
      for (var i = 0; i < selectedNodes.length; i++) {
        selectedNodes[i].activateSilently(); //Opens the tree up so that the selected values are displayed.					
      }
    },
    onSelect: function(select, node){
      if (!select){
        var selectedNodes = node.tree.getSelectedNodes();
        if (selectedNodes.length == 0){
          node.select();
          alert (Drupal.t('You must select at least one location.')); // Stops the user sending back a response with no locations set.
        }
      }
    }
  });
});