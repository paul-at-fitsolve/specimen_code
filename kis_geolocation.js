/**
 * @file
 *
 * Manages geolocation
 */

(function($, Drupal){
  'use strict';

  Drupal.behaviors.kisGeolocation = {
    attach: function(context) {
      // Get cookies and compare to current country
      var currentCountry = Drupal.settings.currentCountryCode;
      var detectedCountry = $.cookie('GEOIP_COUNTRY_CODE');
      var decided = $.cookie('market_decided');
      var row;

      if ((decided == undefined || decided == 0) && detectedCountry && currentCountry && currentCountry != detectedCountry) {
        var geolocationPane = $('#block-views-languages-geolocation-pane', context);
        var icon = geolocationPane.find('.icon');
        geolocationPane.find('.close a').click(function(event) {
          $.cookie('market_decided', 1, { path: '/' });
          $('#block-views-languages-geolocation-pane').slideUp();
          icon.removeClass('open').addClass('closed');
          event.preventDefault();
        });

        geolocationPane.find('.views-row').each(function () {
          row = $(this);
          if (!row.hasClass(currentCountry) && !row.hasClass(detectedCountry)) {
            row.hide();
          } else {
            row.find('a').click(function() {
              $.cookie('market_decided', 1, { path: '/' });
            });
          }
        });

        setTimeout(function() {
          geolocationPane.slideDown();
          icon.addClass('open');
        }, 1000);
      }
    }
  }
})(jQuery, Drupal);
