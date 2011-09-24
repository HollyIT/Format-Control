(function($){
  var uuid = 0;
  Drupal.behaviors.formatControlLink = {
    attach: function (context, settings){
      
      $('.format-control-dialog-link a', context).once(function(){
        var base = $(this).attr('href'),
        elem = $(this);
        $(this).parents('.fieldset-wrapper').find('select').change(function(){
          elem.attr('href', base + '/' + $('option:selected', this).val())
        }).trigger('change')
        elem
        .addClass('ctools-use-modal-processed')
        .click(Drupal.CTools.Modal.clickAjaxLink)
        .each(function () {
          uuid++;
          var element_settings = {};
          element_settings.url = '';
          element_settings.beforeSerialize = function(element, options){
          
            options.url =  elem.attr('href')
          };
          element_settings.event = 'click';
          element_settings.progress = {
            type: 'throbber'
          };        
          Drupal.ajax['filter-control-link-' + uuid] = new Drupal.ajax('', this, element_settings);

        // Attach the display behavior to the ajax object
        }
        );

        
      })

    }
  }
})(jQuery)
 
